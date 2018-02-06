
#include "ground1.h"

Ground1::Ground1( )
{
    //IAnimatedMesh *iamesh = smgr->getMesh("levels/terrain.obj");
	IAnimatedMesh *iamesh = smgr->getMesh("levels/land.3ds");
    IMesh *imesh=iamesh->getMesh(0);
    s32 vertex_count=imesh->getMeshBuffer(0)->getVertexCount( );
    S3DVertex *vertex = (S3DVertex *) imesh->getMeshBuffer(0)->getVertices( );
    u16 *index=imesh->getMeshBuffer(0)->getIndices( );
    
    node=smgr->addAnimatedMeshSceneNode( iamesh );
    node->setMaterialTexture(0, driver->getTexture("levels/1.jpg"));
    node->setMaterialFlag(EMF_LIGHTING, false);
	node->addShadowVolumeSceneNode(-1,false);
    
    NewtonCollision* collision = NewtonCreateTreeCollision(nWorld, 0);

    NewtonTreeCollisionBeginBuild(collision);
        dFloat temp[9];
        for (int i=0; i<vertex_count; i+=3){
            for (int q=0, j=0; j<3; j++){
                temp[q]=vertex[ index[j+i] ].Pos.X; q++;
                temp[q]=vertex[ index[j+i] ].Pos.Y; q++;
                temp[q]=vertex[ index[j+i] ].Pos.Z; q++;
            }
            NewtonTreeCollisionAddFace(collision, 3, temp, 3*sizeof(dFloat), 1);
        }
    NewtonTreeCollisionEndBuild(collision, 1);

    body = NewtonCreateBody (nWorld, collision);

    matrix4 m;
    dFloat world_size_1[3];
    dFloat world_size_2[3];
    NewtonCollisionCalculateAABB(collision, m.M, world_size_1, world_size_2);
    NewtonSetWorldSize(nWorld, world_size_1, world_size_2);

    NewtonReleaseCollision (nWorld, collision);
    NewtonBodySetUserData(body, this);
	
	levelID = NewtonMaterialCreateGroupID(nWorld);
	NewtonBodySetMaterialGroupID (body, levelID);
    
    smgr->addSkyBoxSceneNode (driver->getTexture("img/s3.jpg"),
                              driver->getTexture("img/s6.jpg"),
                              driver->getTexture("img/s2.jpg"),
                              driver->getTexture("img/s5.jpg"),
                              driver->getTexture("img/s1.jpg"),
                              driver->getTexture("img/s4.jpg"));
}  


Ground1::~Ground1( )
{
    node->remove( );
    NewtonDestroyBody(nWorld, body);
}


void Ground1::Transform (const dFloat* matrix)
{
    matrix4 m; for (int i=0; i<16; i++) m.M[i]=matrix[i];
    node->setPosition( m.getTranslation( ) );
}


void Ground1::setObjPosition(const vector3df &vector)
{
    matrix4 m;
    NewtonBodyGetMatrix(body, m.M);
    vector3df v=m.getTranslation( );
    v+=vector;
    m.setTranslation( v );
    NewtonBodySetMatrix(body, m.M);
}
