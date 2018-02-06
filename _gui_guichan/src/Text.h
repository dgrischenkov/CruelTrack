

#pragma once
#include <guichan.hpp>


class Text : public gcn::TextBox
{
public:
	Text(char *text, int w, int h=0, gcn::ImageFont *font=0);

	virtual void keyPress (const gcn::Key &key);
};

