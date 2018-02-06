
#include "gui.h"

#include "_ilevels.h"
#include "../levels/level1.h"
#include "CEGUI.h"
#include "RendererModules/IrrlichtRenderer/irrlichtrenderer.h"

using namespace CEGUI;


Gui::Gui(IrrlichtDevice *device, IVideoDriver *driver)
{
	d_device=device;
    d_driver=driver;
    d_lastTime = device->getTimer()->getRealTime( );
	d_renderer=new IrrlichtRenderer(device, false);
    new System(d_renderer);

	CEGUI::Imageset::setDefaultResourceGroup("gui");
	CEGUI::Font::setDefaultResourceGroup("gui");
	CEGUI::Scheme::setDefaultResourceGroup("gui");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("gui");
	CEGUI::WindowManager::setDefaultResourceGroup("gui");
	CEGUI::ScriptModule::setDefaultResourceGroup("gui");

    DefaultResourceProvider* rp = static_cast<DefaultResourceProvider*>
        (System::getSingleton().getResourceProvider());

    rp->setResourceGroupDirectory("gui", "gui/");

    current_level=0;
    init_main_menu( );
}


Gui::~Gui( )
{

}


void Gui::render( )
{
    static char buf[8];
    if (current_level){
        itoa(d_driver->getFPS( ), buf, 10);
        ed[0]->setText(buf);
        current_level->update( );
    }
	System::getSingleton().renderGUI();
}


void Gui::pre_render( )
{
	u32 currTime = d_device->getTimer()->getRealTime();
	System::getSingleton().injectTimePulse(static_cast<float>(currTime - d_lastTime) / 1000.0f);
	d_lastTime = currTime;
}


bool Gui::OnEvent(irr::SEvent event)
{
	if ( event.KeyInput.Char > 0 && event.KeyInput.Char < 255 )
		key_input[event.KeyInput.Char]=event.KeyInput.PressedDown;

    return (d_renderer != 0) ? d_renderer->OnEvent(event) : false;
}


void Gui::init_main_menu( )
{
    WindowManager& winMgr = WindowManager::getSingleton();
    SchemeManager::getSingleton().loadScheme("TaharezLook.scheme");
    System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");
    FontManager::getSingleton().createFont("europe.font");
    Window* sheet = winMgr.createWindow("DefaultWindow", "root_wnd");
    System::getSingleton().setGUISheet(sheet);

    ImagesetManager::getSingleton().createImagesetFromImageFile("BackgroundImage", "fon.jpg");

    guisheet = winMgr.createWindow("TaharezLook/StaticImage", "guisheet");
    guisheet->setPosition(UVector2(cegui_reldim(0), cegui_reldim( 0)));
    guisheet->setSize(UVector2(cegui_reldim(1), cegui_reldim( 1)));
    guisheet->setProperty("Image", "set:BackgroundImage image:full_image");
    sheet->addChildWindow(guisheet);

    hudsheet = winMgr.createWindow("DefaultWindow", "hudsheet");
    hudsheet->setVisible(false);
    sheet->addChildWindow(hudsheet);

    btn[0] = static_cast<PushButton*>(winMgr.createWindow("TaharezLook/Button", "GameButton"));
    guisheet->addChildWindow(btn[0]);
    btn[0]->setText("Играть");
    btn[0]->setPosition(UVector2(cegui_reldim(0.05f), cegui_reldim( 0.25f)));
    btn[0]->setSize(UVector2(cegui_reldim(0.25f), cegui_reldim( 0.09f)));
    btn[0]->subscribeEvent(PushButton::EventClicked, Event::Subscriber(&Gui::event_but_game, this));

    btn[1] = static_cast<PushButton*>(winMgr.createWindow("TaharezLook/Button", "QuitButton"));
    guisheet->addChildWindow(btn[1]);
    btn[1]->setText("Выход");
    btn[1]->setPosition(UVector2(cegui_reldim(0.05f), cegui_reldim( 0.38f)));
    btn[1]->setSize(UVector2(cegui_reldim(0.25f), cegui_reldim( 0.09f)));
    btn[1]->subscribeEvent(PushButton::EventClicked, Event::Subscriber(&Gui::event_but_quit, this));

    ed[0] = static_cast<Editbox*>(winMgr.createWindow("TaharezLook/StaticText", "fps"));
    hudsheet->addChildWindow(ed[0]);
    ed[0]->setText("qwe");
    ed[0]->setPosition(UVector2(cegui_reldim(0.01f), cegui_reldim( 0.01f)));
    ed[0]->setSize(UVector2(cegui_reldim(0.15f), cegui_reldim( 0.06f)));

}


bool Gui::event_but_game(const EventArgs& e)
{
    current_level=level1=new Level1( );
    guisheet->setVisible(false);
    MouseCursor::getSingleton( ).setVisible(false);
    hudsheet->setVisible(true);
    return true;
}


bool Gui::event_but_quit(const EventArgs& e)
{
    d_device->closeDevice( );
    return true;
}
