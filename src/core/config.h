
/*
  Name: config.h
  Copyright: 
  Author: FLUF
  Date: 07.10.06 17:46
  Description: 
*/


#ifndef CONFIG_H
#define CONFIG_H

#include "log.h"

class Config
{
public:
	Config( );
	~Config( );

	bool screen_full;
	bool screen_stencil;
	bool screen_vsync;
	int screen_w;
	int screen_h;
	int screen_bpp;

};

#endif
