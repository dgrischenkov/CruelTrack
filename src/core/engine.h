
#ifndef ENGINE_H
#define ENGINE_H

#include <math.h>
#include <irrlicht.h>
#include <newton.h>
#include "config.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

struct HudVars {
	bool level_exit;
};
extern HudVars *hudvars;

extern IrrlichtDevice *device;
extern IVideoDriver *driver;
extern ISceneManager *smgr;
extern NewtonWorld *nWorld;
extern bool *key_input;
extern Config *config;

extern int	vehicleID;
extern int	levelID;

extern void ForceAndTorqueCallback (const NewtonBody* body);
extern void TransformCallback (const NewtonBody* body, const dFloat* matrix);

#define PI							3.14159265358979323846f
#define DEGTORAD(a)					(((a) * PI) / 180.0f)
#define RADTODEG(a)					(((a) * 180.0f) / PI)
#define	SIN(x)						sinf(DEGTORAD(x))
#define	COS(x)						cosf(DEGTORAD(x))

#define SQR(x)						((x) * (x))
#define SQRT(x)						sqrtf(x)
#define MAX(a,b)					((a < b) ? (b) : (a))
#define MIN(a,b)					((a < b) ? (a) : (b))
#define ABS(a)						fabs(a)
    
#endif
