

#pragma once
#include <stdio.h>
#include <cstring>

class Conf
{
public:
	Conf( );

	bool fullscrean;
	int resolution;
	int bitpicsel;
	int volume_sound;
	int volume_music;
	int level_texture;
	int level_effect;
	int gui [12][3];
	char *text[3];
};

