

#pragma once
#pragma comment(lib, "lib/guichan.lib")
#pragma comment(lib, "lib/guichan_opengl.lib")
#pragma comment(lib, "lib/guichan_sdl.lib")
#pragma comment(lib, "lib/sdl.lib")
#pragma comment(lib, "lib/sdl_image.lib")
#pragma comment(lib, "lib/sdlmain.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")


#include "Render.h"
#include "Conf.h"

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>


extern Render *render;
extern Conf *conf;


class Init
{

public:
	Init( );

};

