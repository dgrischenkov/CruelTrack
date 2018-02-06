

#pragma once
#include "Icon.h"


class Button : public gcn::Button
{
	Icon *ic_pos;
	Icon *ic_act;
	Icon *ic_cli;

public:
	Button(const std::string &eventId, Icon *im0, Icon *im1, Icon *im2);
	void SetOptions(int time_start, int time_wait, bool revers=true);

	virtual void draw(gcn::Graphics *graphics);
	virtual void drawBorder (gcn::Graphics *graphics);
};

