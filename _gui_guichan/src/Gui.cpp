

#include "Gui.h"


Gui::Gui(int w, int h)
{
	hostImageLoader = new gcn::SDLImageLoader( );
	imageLoader = new gcn::OpenGLImageLoader( );
	imageLoader->setHostImageLoader(hostImageLoader);
	gcn::Image::setImageLoader(imageLoader);

	graphics = new gcn::OpenGLGraphics(w, h);

	top=new gcn::Container( );
	top->setDimension(gcn::Rectangle(0, 0, w, h));
	
	gui=new gcn::Gui( );
	gui->setGraphics(graphics);
	gui->setInput(input->GetSDLInput( ));	
	gui->setTop(top);

	str_of_font=new char[255];
	strcpy(str_of_font, "йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАП"
						"РОЛДЖЭЯЧСМИТЬБЮqwertyuiopasdfghjklzxcvbnmQWERTYUIOP"
						"ASDFGHJKLZXCVBNM `1234567890-=~!@#$%^&*()_+/\\|<>.,:;[]{}’\"?ёЁ");

	font[0] = new gcn::ImageFont("data/font/font1.tga",str_of_font);
	font[1] = new gcn::ImageFont("data/font/font2.tga",str_of_font);
	font[2] = new gcn::ImageFont("data/font/font3.tga",str_of_font);
	font[3] = new gcn::ImageFont("data/font/font4.tga",str_of_font);
	font[4] = new gcn::ImageFont("data/font/font5.tga",str_of_font);
	font[5] = new gcn::ImageFont("data/font/font6.tga",str_of_font);
	gcn::Widget::setGlobalFont(font[0]);

	fon_image[0]=new gcn::Image("data/menu/fon.jpg");
	fon_image[1]=new gcn::Image("data/menu/fondialog.png");
	fon_image[2]=new gcn::Image("data/menu/fonbigdialog.png");
	fon_icon[0]=new gcn::Icon(fon_image[0]);
	fon_icon[1]=new gcn::Icon(fon_image[2]);
	fon_icon[2]=new gcn::Icon(fon_image[2]);
	fon_icon[3]=new gcn::Icon(fon_image[2]);
	fon_icon[4]=new gcn::Icon(fon_image[2]);
	fon_icon[5]=new gcn::Icon(fon_image[2]);
	fon_icon[6]=new gcn::Icon(fon_image[2]);
	fon_icon[7]=new gcn::Icon(fon_image[1]);

	icon[ 0]=new Icon("data/menu/main1_p.jpg",	conf->gui[0][2]);
	icon[ 1]=new Icon("data/menu/main1_a.jpg",	conf->gui[0][2]);
	icon[ 2]=new Icon("data/menu/main1_c.jpg",	conf->gui[0][2]);
	icon[ 3]=new Icon("data/menu/main2_p.jpg",	conf->gui[1][2]);
	icon[ 4]=new Icon("data/menu/main2_a.jpg",	conf->gui[1][2]);
	icon[ 5]=new Icon("data/menu/main2_c.jpg",	conf->gui[1][2]);
	icon[ 6]=new Icon("data/menu/main3_p.jpg",	conf->gui[2][2]);
	icon[ 7]=new Icon("data/menu/main3_a.jpg",	conf->gui[2][2]);
	icon[ 8]=new Icon("data/menu/main3_c.jpg",	conf->gui[2][2]);
	icon[ 9]=new Icon("data/menu/main4_p.jpg",	conf->gui[3][2]);
	icon[10]=new Icon("data/menu/main4_a.jpg",	conf->gui[3][2]);
	icon[11]=new Icon("data/menu/main4_c.jpg",	conf->gui[3][2]);
	icon[12]=new Icon("data/menu/main5_p.jpg",	conf->gui[4][2]);
	icon[13]=new Icon("data/menu/main5_a.jpg",	conf->gui[4][2]);
	icon[14]=new Icon("data/menu/main5_c.jpg",	conf->gui[4][2]);
	icon[15]=new Icon("data/menu/main6_p.jpg",	conf->gui[5][2]);
	icon[16]=new Icon("data/menu/main6_a.jpg",	conf->gui[5][2]);
	icon[17]=new Icon("data/menu/main6_c.jpg",	conf->gui[5][2]);
	icon[18]=new Icon("data/menu/main7_p.jpg",	conf->gui[6][2]);
	icon[19]=new Icon("data/menu/main7_a.jpg",	conf->gui[6][2]);
	icon[20]=new Icon("data/menu/main7_c.jpg",	conf->gui[6][2]);
	icon[21]=new Icon("data/menu/yes_p.jpg",	conf->gui[7][2]);
	icon[22]=new Icon("data/menu/yes_a.jpg",	conf->gui[7][2]);
	icon[23]=new Icon("data/menu/yes_c.jpg",	conf->gui[7][2]);
	icon[24]=new Icon("data/menu/no_p.jpg",		conf->gui[8][2]);
	icon[25]=new Icon("data/menu/no_a.jpg",		conf->gui[8][2]);
	icon[26]=new Icon("data/menu/no_c.jpg",		conf->gui[8][2]);
	icon[27]=new Icon("data/menu/done_p.jpg",	conf->gui[9][2]);
	icon[28]=new Icon("data/menu/done_a.jpg",	conf->gui[9][2]);
	icon[29]=new Icon("data/menu/done_c.jpg",	conf->gui[9][2]);
	icon[30]=new Icon("data/menu/cancel_p.jpg",	conf->gui[10][2]);
	icon[31]=new Icon("data/menu/cancel_a.jpg",	conf->gui[10][2]);
	icon[32]=new Icon("data/menu/cancel_c.jpg",	conf->gui[10][2]);
	icon[33]=new Icon("data/menu/ongame_p.jpg", conf->gui[11][2]);
	icon[34]=new Icon("data/menu/ongame_a.jpg", conf->gui[11][2]);
	icon[35]=new Icon("data/menu/ongame_c.jpg", conf->gui[11][2]);
	icon[36]=new Icon("data/menu/heros1_p.jpg");
	icon[37]=new Icon("data/menu/heros1_a.jpg");
	icon[38]=new Icon("data/menu/heros1_c.jpg");
	icon[39]=new Icon("data/menu/heros2_p.jpg");
	icon[40]=new Icon("data/menu/heros2_a.jpg");
	icon[41]=new Icon("data/menu/heros2_c.jpg");
	icon[42]=new Icon("data/menu/heros3_p.jpg");
	icon[43]=new Icon("data/menu/heros3_a.jpg");
	icon[44]=new Icon("data/menu/heros3_c.jpg");

	InitTop( );

	InitLayer0( );
	InitLayer1( );
	InitLayer2( );
	InitLayer3( );
	InitLayer4( );
	InitLayer5( );
	InitLayer6( );
}


void Gui::InitTop( ){
	but[0]=new Button("newgame",	icon[ 0], icon[ 1], icon[ 2]);
	but[1]=new Button("selfgame",	icon[ 3], icon[ 4], icon[ 5]);
	but[2]=new Button("load",		icon[ 6], icon[ 7], icon[ 8]);
	but[3]=new Button("config",		icon[ 9], icon[10], icon[11]);
	but[4]=new Button("records",	icon[12], icon[13], icon[14]);
	but[5]=new Button("about",		icon[15], icon[16], icon[17]);
	but[6]=new Button("exit",		icon[18], icon[19], icon[20]);

	top->add(fon_icon[0]);
	for (int i=0; i<7; i++){
		but[i]->SetOptions(7000-100*i, 8000);
		but[i]->addActionListener(this);
		top->add(but[i], conf->gui[i][0], conf->gui[i][1]);
	}

	for (int n=0; n<7; n++){
		layer[n]=new gcn::Container( );
		layer[n]->setVisible(false);
		layer[n]->setOpaque(false);
		layer[n]->add(fon_icon[n+1]);
		layer[n]->setDimension(*InCenter(fon_icon[n+1]));
		top->add(layer[n]);
	}
}


void Gui::InitLayer0( )
{
	label[0]=new gcn::Label("# Нов@я игра #");
	label[0]->setFont(font[4]);
	label[0]->adjustSize( );
	label[1]=new gcn::Label("Выберите персонажа, за которого будете играть:");
	label[1]->setFont(font[2]);
	label[2]=new gcn::Label("Краткая характеристика:");
	label[2]->setFont(font[2]);
	label[3]=new gcn::Label("Уровень сложности:");
	label[3]->setFont(font[2]);
	label[4]=new gcn::Label("Ваше имя, для статистики рекордов:");
	label[4]->setFont(font[2]);

	but[7]=new Button("heros1",				icon[36], icon[37], icon[38]);
	but[8]=new Button("heros2",				icon[39], icon[40], icon[41]);
	but[9]=new Button("heros3",				icon[42], icon[43], icon[44]);
	but[10]=new Button("ongame",			icon[33], icon[34], icon[35]);
	but[11]=new Button("newgame_cancel",	icon[30], icon[31], icon[32]);
	but[7]->setBorderSize(1);
	but[7]->addActionListener(this);
	but[8]->addActionListener(this);
	but[9]->addActionListener(this);
	but[10]->addActionListener(this);
	but[11]->addActionListener(this);

	chouse[0]=new Chouse("чмошник,неудачник,нормальный,"
		"крутой,бог", 2, font[1], font[0], font[0]);

	textfield=new gcn::TextField("Дефолт");
	textfield->setBackgroundColor(gcn::Color(0,0,0,0));
	textfield->setForegroundColor(gcn::Color(230, 120, 60, 255));
	textfield->setBorderSize(0);
	textfield->setFont(font[1]);
	textfield->setSize(150, font[1]->getHeight( ));

	text[0]=new Text(conf->text[0], 500);
	scroll[0]=new Scroll(text[0]);
	scroll[0]->setSize(520, 100);
	scroll[0]->setBackgroundColor(gcn::Color(0,0,0,0));
	text[1]=new Text(conf->text[1], 500);
	scroll[1]=new Scroll(text[1]);
	scroll[1]->setSize(520, 100);
	scroll[1]->setBackgroundColor(gcn::Color(0,0,0,0));
	scroll[1]->setVisible(false);
	text[2]=new Text(conf->text[2], 500);
	scroll[2]=new Scroll(text[2]);
	scroll[2]->setSize(520, 100);
	scroll[2]->setBackgroundColor(gcn::Color(0,0,0,0));
	scroll[2]->setVisible(false);

	layer[0]->add(label[0], 35, 30);
	layer[0]->add(label[1], 60, 60);
	layer[0]->add(label[2], 60, 209);
	layer[0]->add(label[3], 60, 350);
	layer[0]->add(label[4], 60, 375);
	layer[0]->add(but[7], 80,  90);
	layer[0]->add(but[8], 270, 90);
	layer[0]->add(but[9], 460, 90);
	layer[0]->add(but[10], conf->gui[11][0], conf->gui[11][1]);
	layer[0]->add(but[11], conf->gui[10][0], conf->gui[10][1]);
	layer[0]->add(chouse[0], 210, 350);
	layer[0]->add(textfield, 330, 375);
	layer[0]->add(scroll[0], 60, 235);
	layer[0]->add(scroll[1], 60, 235);
	layer[0]->add(scroll[2], 60, 235);
}


void Gui::InitLayer1( )
{
	label[5]=new gcn::Label("# $вободная игра #");
	label[5]->setFont(font[4]);
	label[5]->adjustSize( );
	label[6]=new gcn::Label("Не доступно в демо версии");
	but[12]=new Button("selfgame_cancel", icon[30], icon[31], icon[32]);
	but[12]->addActionListener(this);

	layer[1]->add(label[5], 35, 30);
	layer[1]->add(label[6], 215, 210);
	layer[1]->add(but[12], conf->gui[10][0], conf->gui[10][1]);
}


void Gui::InitLayer2( )
{
	label[7]=new gcn::Label("# ЗагруzитЪ #");
	label[7]->setFont(font[4]);
	label[7]->adjustSize( );
	label[8]=new gcn::Label("Не доступно в демо версии");
	but[13]=new Button("load_cancel", icon[30], icon[31], icon[32]);
	but[13]->addActionListener(this);

	layer[2]->add(label[7], 35, 30);
	layer[2]->add(label[8], 215, 210);
	layer[2]->add(but[13], conf->gui[10][0], conf->gui[10][1]);
}


void Gui::InitLayer3( )
{
	label[ 9]=new gcn::Label("Полный экран:");
	label[10]=new gcn::Label("Разрешение:");
	label[11]=new gcn::Label("Бит на пиксель:");
	label[12]=new gcn::Label("Громкость музыки:");
	label[13]=new gcn::Label("Громкость звуков:");
	label[14]=new gcn::Label("Качество текстур:");
	label[15]=new gcn::Label("Качество эффектов:");
	label[16]=new gcn::Label("# |-|астройкi #");
	label[16]->setFont(font[4]);
	label[16]->adjustSize( );

	for (int i=9; i<16; i++){
		label[i]->setFont(font[2]);
		label[i]->setSize(150, font[2]->getHeight( ));
		label[i]->setAlignment(gcn::Graphics::RIGHT);
	}

	but[14]=new Button("config_cancel", icon[30], icon[31], icon[32]);
	but[14]->addActionListener(this);

	chouse[1]=new Chouse("нет,да", 
		conf->fullscrean, font[1], font[0], font[0]);

	chouse[2]=new Chouse("640x480,800x600,1024x768", 
		conf->resolution, font[1], font[0], font[0]);

	chouse[3]=new Chouse("16,32", 
		conf->bitpicsel, font[1], font[0], font[0]);

	chouse[4]=new Chouse("100%,90%,80%,70%,60%,50%,40%,30%,20%,10%,0%",
		conf->volume_music, font[1], font[0], font[0]);

	chouse[5]=new Chouse("100%,90%,80%,70%,60%,50%,40%,30%,20%,10%,0%",
		conf->volume_sound, font[1], font[0], font[0]);

	chouse[6]=new Chouse("низко,средне,высоко", 
		conf->level_texture, font[1], font[0], font[0]);

	chouse[7]=new Chouse("низко,средне,высоко", 
		conf->level_effect, font[1], font[0], font[0]);

	layer[3]->add(label[ 9], 180, 130);
	layer[3]->add(label[10], 180, 155);
	layer[3]->add(label[11], 180, 180);
	layer[3]->add(label[12], 180, 205);
	layer[3]->add(label[13], 180, 230);
	layer[3]->add(label[14], 180, 255);
	layer[3]->add(label[15], 180, 280);
	layer[3]->add(label[16], 35, 30);
	layer[3]->add(but[14], conf->gui[10][0], conf->gui[10][1]);
	layer[3]->add(chouse[1], 340, 130);
	layer[3]->add(chouse[2], 340, 155);
	layer[3]->add(chouse[3], 340, 180);
	layer[3]->add(chouse[4], 340, 205);
	layer[3]->add(chouse[5], 340, 230);
	layer[3]->add(chouse[6], 340, 255);
	layer[3]->add(chouse[7], 340, 280);
}


void Gui::InitLayer4( )
{
	label[17]=new gcn::Label("# RекордЬI #");
	label[17]->setFont(font[4]);
	label[17]->adjustSize( );
	label[18]=new gcn::Label("Не доступно в демо версии");
	but[16]=new Button("records_cancel", icon[30], icon[31], icon[32]);
	but[16]->addActionListener(this);

	layer[4]->add(label[17], 35, 30);
	layer[4]->add(label[18], 215, 210);
	layer[4]->add(but[16], conf->gui[10][0], conf->gui[10][1]);
}


void Gui::InitLayer5( )
{
	label[19]=new gcn::Label("# Создатели #");
	label[19]->setFont(font[4]);
	label[19]->adjustSize( );
	label[20]=new gcn::Label("Самиздат. Автогенерирующийся код и саморисующиеся картинки ^_^");
	but[17]=new Button("about_cancel", icon[30], icon[31], icon[32]);
	but[17]->addActionListener(this);

	layer[5]->add(label[19], 35, 30);
	layer[5]->add(label[20], 75, 210);
	layer[5]->add(but[17], conf->gui[10][0], conf->gui[10][1]);
}


void Gui::InitLayer6( )
{
	but[18]=new Button("exit_done",		icon[21], icon[22], icon[23]);
	but[19]=new Button("exit_cancel",	icon[24], icon[25], icon[26]);
	but[18]->addActionListener(this);
	but[19]->addActionListener(this);

	label[21]=new gcn::Label("Вы уверены, что хотите выйти?");

	layer[6]->add(but[18], 50, 130);
	layer[6]->add(but[19], 210, 130);
	layer[6]->add(label[21], 80, 60);
}

void Gui::action (const std::string &eventId)
{
	static gcn::Container *activ_layer=0;

	layer[6]->setVisible(false);

	if (eventId=="newgame"){
		if (activ_layer) activ_layer->setVisible(false);
		layer[0]->setVisible(true);
		activ_layer=layer[0];
	}
	if (eventId=="selfgame"){
		if (activ_layer) activ_layer->setVisible(false);
		layer[1]->setVisible(true);
		activ_layer=layer[1];
	}
	if (eventId=="load"){
		if (activ_layer) activ_layer->setVisible(false);
		layer[2]->setVisible(true);
		activ_layer=layer[2];
	}
	if (eventId=="config"){
		if (activ_layer) activ_layer->setVisible(false);
		layer[3]->setVisible(true);
		activ_layer=layer[3];
	}
	if (eventId=="records"){
		if (activ_layer) activ_layer->setVisible(false);
		layer[4]->setVisible(true);
		activ_layer=layer[4];
	}
	if (eventId=="about"){
		if (activ_layer) activ_layer->setVisible(false);
		layer[5]->setVisible(true);
		activ_layer=layer[5];
	}
	if (eventId=="exit") layer[6]->setVisible(true);

	if (eventId=="newgame_cancel") layer[0]->setVisible(false);
	if (eventId=="selfgame_cancel") layer[1]->setVisible(false);
	if (eventId=="load_cancel") layer[2]->setVisible(false);
	if (eventId=="config_cancel") layer[3]->setVisible(false);
	if (eventId=="records_cancel") layer[4]->setVisible(false);
	if (eventId=="about_cancel") layer[5]->setVisible(false);

	//	*******************

	static int activ_heros=0;

	if (eventId=="exit_done") exit(0);

	if (eventId=="heros1"){
		but[activ_heros+7]->setBorderSize(0);
		but[7]->setBorderSize(1);
		scroll[activ_heros]->setVisible(false);
		scroll[0]->setVisible(true);
		activ_heros=0;
	}
	if (eventId=="heros2"){
		but[activ_heros+7]->setBorderSize(0);
		but[8]->setBorderSize(1);
		scroll[activ_heros]->setVisible(false);
		scroll[1]->setVisible(true);
		activ_heros=1;
	}
	if (eventId=="heros3"){
		but[activ_heros+7]->setBorderSize(0);
		but[9]->setBorderSize(1);
		scroll[activ_heros]->setVisible(false);
		scroll[2]->setVisible(true);
		activ_heros=2;
	}

}


gcn::Rectangle *Gui::InCenter(gcn::Icon *fon_icon)
{
	return &gcn::Rectangle((top->getWidth( )-fon_icon->getWidth( ))/2,
		(top->getHeight( )-fon_icon->getHeight( ))/2,
		fon_icon->getWidth( ), fon_icon->getHeight( ));
}


Gui::~Gui( ){ }


void Gui::Draw( )
{
	if (input->event->type == SDL_KEYDOWN && 
		input->event->key.keysym.sym == SDLK_ESCAPE){
		layer[6]->setVisible(true);
	}

	gui->logic( );
	gui->draw( );
}

