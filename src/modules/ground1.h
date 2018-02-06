
#ifndef GROUND1_H
#define GROUND1_H

#include "../core/_iobjects.h"

class Ground1 : iObjects
{
    IAnimatedMeshSceneNode *node;
	//ISceneNode *node;
    NewtonBody *body;
    
public:
    Ground1( );
    ~Ground1( );

    virtual void ForceAndTorque( ){ };
    virtual void Transform(const dFloat* matrix);
    
    virtual void setObjPosition(const vector3df &vector);
    virtual void setObjRotation(const vector3df &vector){ };
};

#endif
