
#ifndef GUI_H
#define GUI_H

#include "engine.h"

class iLevels;
class Level1;

namespace CEGUI {
	class IrrlichtRenderer;
    class EventArgs;
    class Window;
    class PushButton;
    class Editbox;
}

class Gui : public irr::IEventReceiver
{
    iLevels *current_level;
    Level1 *level1;

    CEGUI::Window *guisheet, *hudsheet;
    CEGUI::PushButton *btn[8];
    CEGUI::Editbox *ed[8];
	CEGUI::IrrlichtRenderer* d_renderer;
	IrrlichtDevice *d_device;
	IVideoDriver *d_driver;
    u32 d_lastTime;

    void init_main_menu( );
    bool event_but_quit(const CEGUI::EventArgs& e);
    bool event_but_game(const CEGUI::EventArgs& e);

public:
    Gui(IrrlichtDevice *device, IVideoDriver *driver);
    ~Gui( );

	void pre_render( );
	void render( );
    virtual bool OnEvent(SEvent event);

};

#endif
