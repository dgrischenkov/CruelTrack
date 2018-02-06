

#include "Input.h"


Input::Input( )
{
	event=new SDL_Event( );
	input=new gcn::SDLInput( );
	input->pushInput(*event);
}


Input::~Input( )
{
	delete event;
	delete input;
}


void Input::go( )
{
	while(SDL_PollEvent(event))
	{
		if (event->type == SDL_KEYDOWN)
		{
//			if (event->key.keysym.sym == SDLK_ESCAPE)
//				running = false;
		}
		else if(event->type == SDL_QUIT)
		{
			running = false;
		}

		input->pushInput(*event);        		
	}
}


gcn::SDLInput *Input::GetSDLInput( )
{
	return input;
}

