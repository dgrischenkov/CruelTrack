
#include "engine.h"
#pragma comment(linker, "/entry:\"mainCRTStartup\"")

#include "gui.h"
#include "_iobjects.h"

IrrlichtDevice *device;
IVideoDriver *driver;
ISceneManager *smgr;
NewtonWorld *nWorld;
bool *key_input;
Config *config;
HudVars *hudvars;

Gui *mygui; // невидимый

int	vehicleID;
int levelID;

void ForceAndTorqueCallback (const NewtonBody* body)
{ ((iObjects *)NewtonBodyGetUserData(body))->ForceAndTorque( ); }


void TransformCallback (const NewtonBody* body, const dFloat* matrix)
{ ((iObjects *)NewtonBodyGetUserData(body))->Transform(matrix); }


int main( )
{
    config=new Config( );

	device=createDevice(video::EDT_DIRECT3D8, // ^_^'
        dimension2d<s32>(config->screen_w, config->screen_h),
        config->screen_bpp,
        config->screen_full,
        config->screen_stencil,
        config->screen_vsync);

    device->setWindowCaption(L"Cruel Track");
    device->getCursorControl()->setVisible(false);
    nWorld = NewtonCreate (NULL, NULL);
	driver = device->getVideoDriver( );
	smgr = device->getSceneManager( );
	
    key_input=new bool[255];
    for (int i=0; i<255; i++) key_input[i]=false;

	hudvars=new HudVars;
	hudvars->level_exit=false;

	mygui=new Gui(device, driver);
	device->setEventReceiver(mygui);

	while (device->run( )){
		mygui->pre_render( ); // оно ничего не делает, но пускай будет
		driver->beginScene(true, true, SColor(0,0,0,0));
			NewtonUpdate (nWorld, 2.0f/(float)driver->getFPS( ));
			smgr->drawAll( );
			mygui->render( );
		driver->endScene();
	}

	return 0;
}
