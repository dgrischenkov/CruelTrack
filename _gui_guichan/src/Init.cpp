

#include "Init.h"


Init::Init( )
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	long style=SDL_HWSURFACE | SDL_OPENGL | SDL_HWACCEL;
	if (conf->fullscrean) style|=SDL_FULLSCREEN;

	int bpp;
	if (conf->bitpicsel==0) bpp=16;
	if (conf->bitpicsel==1) bpp=32;

	SDL_SetVideoMode(800, 600, bpp, style);

	SDL_EnableUNICODE(1);
	SDL_EnableKeyRepeat(350, 30);

	int w, h;
	if (conf->resolution==0){
		w=640; h=480;
	}
	if (conf->resolution==1){
		w=800; h=600;
	}
	if (conf->resolution==2){
		w=1024; h=768;
	}

	render->GuiInit(800, 600);
	render->SceneInit(w, h);
}


