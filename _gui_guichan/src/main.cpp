

/*	ƒл€ компил€ции в свойствах проекта надо поставить:
	- C/C++ -> Code Generation -> Runtime Library -> 
	Multy-threaded DLL (/MD) */


#include "Conf.h"
#include "Init.h"
#include "Input.h"
#include "Calc.h"
#include "Render.h"


Conf *conf;
Input *input;
Render *render;
Calc *calc;
Init *init;


Uint32 delta_time;
bool running = true;


int main(int argc, char **argv)
{
	Uint32 ticks;

	input=new Input( );
	calc=new Calc( );
	render=new Render( );

	conf=new Conf( );
	init=new Init( );

	while(running)
	{
		ticks=SDL_GetTicks( );

		input->go( );
		calc->go( );
		render->go( );

		SDL_Delay(10);

		delta_time=SDL_GetTicks()-ticks;
	}

	return 0;
}

