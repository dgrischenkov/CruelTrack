

#include <guichan.hpp>
#include <guichan/sdl.hpp>


extern Uint32 delta_time;


class Icon
{
	gcn::Image *res_image;
	int height;
	bool revers;
	int seek_height;
	int animate_status;
	Uint32 tick;
	Uint32 time_wait;
	int time_frame;
	bool visible;


public:
	Icon(char *file_name, int height=0);
	~Icon( );

	void draw(gcn::Graphics *graphics);
	void SetRevers(bool revers);
	void GetWH(int *w, int *h);
	void SetTimeStart(Uint32 time_start);
	void SetTimeWait(Uint32 time_wait);
	void SetVisible(bool visible);
};

