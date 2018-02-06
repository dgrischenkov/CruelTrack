

#pragma once

#include "Gui.h"
#include "Scene.h"

class Render
{
	Gui *gui;
	Scene *scene;

public:
	Render( );
	~Render( );

	void GuiInit(int w, int h);
	void SceneInit(int w, int h);
	void go( );

};

