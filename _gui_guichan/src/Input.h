

#pragma once
#include <guichan/sdl.hpp>


extern bool running;


class Input
{
	gcn::SDLInput *input;

public:
	Input( );
	~Input( );

	void go( );
	gcn::SDLInput *GetSDLInput( );

	SDL_Event *event;
};

