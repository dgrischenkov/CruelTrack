

#include "Render.h"


Render::Render( ){ }


Render::~Render( )
{
	delete gui;
	delete scene;
}


void Render::GuiInit(int w, int h)
{
	gui=new Gui(w, h);
}


void Render::SceneInit(int w, int h)
{
	scene=new Scene(w, h);
}


void Render::go( )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gui->Draw( );
//	scene->Draw( );

	SDL_GL_SwapBuffers( );
}

