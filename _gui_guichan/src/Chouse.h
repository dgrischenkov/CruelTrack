

#pragma once
#include <guichan.hpp>


class Chouse : public gcn::Button, public gcn::ActionListener
{
	gcn::ImageFont *font_pos;
	gcn::ImageFont *font_act;
	gcn::ImageFont *font_cli;
	int cur_position;
	int max_position;
	char values[255][255];

public:
	Chouse(char *values, int start_position,
		gcn::ImageFont *font0, gcn::ImageFont *font1,
		gcn::ImageFont *font2);

	int GetPosition( );

	virtual void draw(gcn::Graphics *graphics);
	virtual void action (const std::string &eventId);

};

