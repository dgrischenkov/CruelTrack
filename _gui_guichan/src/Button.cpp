

#include "Button.h"


Button::Button(const std::string &eventId, Icon *im0,
			   Icon *im1, Icon *im2) : gcn::Button(eventId)
{
	this->setEventId(eventId);
	ic_pos=im0;
	ic_act=im1;
	ic_cli=im2;

	int w, h;
	im0->GetWH(&w, &h);
	setSize(w, h);

	setBorderSize(0);
}


void Button::SetOptions(int time_start, int time_wait, bool revers)
{
	ic_pos->SetTimeStart(time_start);
	ic_pos->SetTimeWait(time_wait);
	ic_pos->SetRevers(revers);
}


void Button::draw(gcn::Graphics *graphics)
{
	if (this->isPressed( )){
		ic_cli->SetVisible(true);
		ic_pos->SetVisible(false);
		ic_act->SetVisible(false);
	} 
	else if (this->hasMouse( )){
		ic_cli->SetVisible(false);
		ic_pos->SetVisible(false);
		ic_act->SetVisible(true);
	}
	else {
		ic_cli->SetVisible(false);
		ic_pos->SetVisible(true);
		ic_act->SetVisible(false);
	}

	ic_act->draw(graphics);
	ic_pos->draw(graphics);
	ic_cli->draw(graphics);

}


void Button::drawBorder (gcn::Graphics *graphics)
{
	graphics->setColor(gcn::Color(255,255,255,255));
	graphics->drawRectangle(gcn::Rectangle(0, 0, getWidth( )+2, getHeight( )+2));
}

