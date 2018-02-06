
#include "level1.h"

Level1::Level1( )
{
 	matrix4 m;
	m.setTranslation(vector3df(0,25,0));
	car = new CCar("_", nWorld, m);
    ground1=new Ground1( );

	NewtonMaterialSetDefaultSoftness (nWorld, vehicleID, levelID, 0.05f);
	NewtonMaterialSetDefaultElasticity (nWorld, vehicleID, levelID, 0.2f);
	NewtonMaterialSetDefaultCollidable (nWorld, vehicleID, levelID, 1);
	NewtonMaterialSetDefaultFriction (nWorld, vehicleID, levelID, 1.0f, 0.6f);

	ILightSceneNode* light1 = smgr->addLightSceneNode(0, vector3df(200,500,200),
		SColorf(0.8f, 0.0f, 0.f, 0.0f), 2000.0f);

	camera = smgr->addCameraSceneNode( );
	camera->setFOV(DEGTORAD(90));
	p_pos.set(0,30,-10);
}

Level1::~Level1( )
{
    delete car;
    delete ground1;
    delete camera;
}


void Level1::update( )
{
	vector3df targ, pos;
	vector3df n_pos, n_targ;
	
	n_targ = car->getDirection().normalize();
	n_pos = car->getPosition() - n_targ*10;
	n_targ *=10;
	n_targ += car->getPosition();
	n_pos.Y += 5;

	pos = (n_pos - p_pos)/20 + p_pos;
	targ = (n_targ - p_targ)/20 + p_targ;
	
	camera->setPosition(pos);
	camera->setTarget(targ);

	p_targ = targ;
	p_pos = pos;
}
