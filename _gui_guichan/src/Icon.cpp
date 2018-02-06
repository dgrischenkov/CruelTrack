

#include "Icon.h"


Icon::Icon(char *file_name, int _height)
{
	res_image=new gcn::Image(file_name);
	_height ? height=_height : height=res_image->getHeight( );
	revers=true;
	seek_height=0;
	animate_status=0;
	tick=0;
	time_wait=0;
	time_frame=83;
	visible=true;
}


Icon::~Icon( )
{
	delete res_image;
}


void Icon::SetVisible(bool _visible)
{
	visible=_visible;
}


void Icon::SetRevers(bool _revers)
{
	revers=_revers;
}


void Icon::GetWH(int *w, int *h)
{
	*w=res_image->getWidth( );
	*h=height;
}



void Icon::SetTimeStart(Uint32 time_start)
{
	tick=time_start;
}


void Icon::SetTimeWait(Uint32 _time_wait)
{
	time_wait=_time_wait;
}


void Icon::draw(gcn::Graphics *graphics)
{
	if (height==res_image->getHeight( )){
		if (visible) graphics->drawImage(res_image, 0, 0);
		return;
	}

	tick+=delta_time;

	if (!animate_status && tick > time_wait){
		animate_status=1;
		tick=0;
	} else if (animate_status==1 && tick > time_frame){
		seek_height+=height;
		if (seek_height+height > res_image->getHeight( )){
			if (revers){
				seek_height-=height;
				animate_status=2;
			} else {
				seek_height=0;
				animate_status=0;
			}
		}
		tick=0;
	} else if (animate_status==2 && tick > time_frame){
		seek_height-=height;
		if (seek_height<0){
			seek_height=0;
			animate_status=0;
		}
		tick=0;
	}

	if (visible) graphics->drawImage(res_image, 0, seek_height,
		0, 0, res_image->getWidth( ), height);
}

