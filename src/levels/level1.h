
#ifndef LEVEL1_H
#define LEVEL1_H

#include "../core/_ilevels.h"
#include "../modules/newtoncar.h"
#include "../modules/ground1.h"

class Level1 : public iLevels
{
	CCar *car;
    Ground1 *ground1;
    ICameraSceneNode *camera;

	vector3df	p_pos;
	vector3df	p_targ;
    
public:
	Level1( );
	~Level1( );

	virtual void update();
};

#endif
