

#pragma once
#include <guichan/opengl.hpp>
#include "Input.h"
#include "Button.h"
#include "Chouse.h"
#include "Text.h"
#include "Scroll.h"
#include "Conf.h"


extern Input *input;
extern Conf *conf;


class Gui : public gcn::ActionListener
{
	gcn::Gui *gui;
	gcn::Container *top;
	gcn::SDLImageLoader *hostImageLoader;
	gcn::OpenGLImageLoader *imageLoader;
	gcn::OpenGLGraphics *graphics;
	gcn::ImageFont *font[6];
	char *str_of_font;

	gcn::Container *layer[7];
	gcn::Image *fon_image[8];
	gcn::Icon *fon_icon[8];

	Text *text[3];
	Scroll *scroll[3];
	gcn::Label *label[255];
	gcn::TextField *textfield;
	Icon *icon[255];
	Button *but[255];
	Chouse *chouse[255];

	gcn::Rectangle *InCenter(gcn::Icon *fon_icon);
	void action (const std::string &eventId);

	void InitTop( );
	void InitLayer0( );
	void InitLayer1( );
	void InitLayer2( );
	void InitLayer3( );
	void InitLayer4( );
	void InitLayer5( );
	void InitLayer6( );

public:
	Gui(int w, int h);
	~Gui( );

	void Draw( );

};

