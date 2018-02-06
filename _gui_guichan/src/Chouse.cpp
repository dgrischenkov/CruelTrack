

#include "Chouse.h"


Chouse::Chouse(char *_values, int start_position,
		gcn::ImageFont *font0, gcn::ImageFont *font1,
		gcn::ImageFont *font2) : gcn::Button("")
{
	font_pos=font0;
	font_act=font1;
	font_cli=font2;

	int cur_new, cur_old=0;
	max_position=-1;
	do {
		max_position++;
		cur_new=strcspn(_values+cur_old, ",");
		strncpy(values[max_position], _values+cur_old, cur_new);
		strcpy(values[max_position]+cur_new, "\0");
		cur_old+=cur_new+1;
	} while ((cur_old-1)!=strlen(_values));

	if (start_position>=0 && start_position<=max_position)
		cur_position=start_position;
	else cur_position=0;

	int max=0;
	for (int i=0; i!=max_position+1; i++)
		if (max < font_pos->getWidth(values[i]))
			max=font_pos->getWidth(values[i]);

	setSize(max, font_pos->getHeight( ));

	setBorderSize(0);
	addActionListener(this);
}


int Chouse::GetPosition( )
{
	return cur_position;
}


void Chouse::action (const std::string &eventId)
{
	cur_position++;
	if (cur_position>max_position)
		cur_position=0;
}


void Chouse::draw(gcn::Graphics *graphics)
{
	static gcn::ImageFont *activ_font;

	if (this->isPressed( ))	activ_font=font_cli;
	else if (this->hasMouse( ))	activ_font=font_act;
	else activ_font=font_pos;

	graphics->setFont(activ_font);
	graphics->drawText(values[cur_position], 0, 0);
}

