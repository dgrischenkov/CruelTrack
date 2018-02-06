
#ifndef IOBJECTS_H
#define IOBJECTS_H

#include "engine.h"

class iObjects
{
public:
    virtual void ForceAndTorque( ) = 0;
    virtual void Transform(const dFloat* matrix) = 0;

    virtual void setObjPosition(const vector3df &vector) = 0;
    virtual void setObjRotation(const vector3df &vector) = 0;

};

#endif
