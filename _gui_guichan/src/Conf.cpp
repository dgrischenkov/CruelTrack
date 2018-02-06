

#include "Conf.h"

Conf::Conf( )
{
	FILE *fp;
	if (!(fp=fopen("conf", "r"))) return;
		fscanf(fp,"FULLSCREAN %i\n", &fullscrean);
		fscanf(fp,"RESOLUTION %i\n", &resolution);
		fscanf(fp,"BITPERPICSEL %i\n", &bitpicsel);
		fscanf(fp,"VOLUMESOUND %i\n", &volume_sound);
		fscanf(fp,"VOLUMEMUSIC %i\n", &volume_music);
		fscanf(fp,"LEVELTEXTURE %i\n", &level_texture);
		fscanf(fp,"LEVELEFFECT %i\n", &level_effect);
	fclose(fp);

	if (!(fp=fopen("gui", "r"))) return;
		fscanf(fp,"Newgame	%i, %i, %i\n", &gui[ 0][0], &gui[ 0][1], &gui[ 0][2]);
		fscanf(fp,"Selfgame	%i, %i, %i\n", &gui[ 1][0], &gui[ 1][1], &gui[ 1][2]);
		fscanf(fp,"Loadgame	%i, %i, %i\n", &gui[ 2][0], &gui[ 2][1], &gui[ 2][2]);
		fscanf(fp,"Config	%i, %i, %i\n", &gui[ 3][0], &gui[ 3][1], &gui[ 3][2]);
		fscanf(fp,"Records	%i, %i, %i\n", &gui[ 4][0], &gui[ 4][1], &gui[ 4][2]);
		fscanf(fp,"About	%i, %i, %i\n", &gui[ 5][0], &gui[ 5][1], &gui[ 5][2]);
		fscanf(fp,"Exit		%i, %i, %i\n", &gui[ 6][0], &gui[ 6][1], &gui[ 6][2]);
		fscanf(fp,"Yes		%i, %i, %i\n", &gui[ 7][0], &gui[ 7][1], &gui[ 7][2]);
		fscanf(fp,"No		%i, %i, %i\n", &gui[ 8][0], &gui[ 8][1], &gui[ 8][2]);
		fscanf(fp,"Done		%i, %i, %i\n", &gui[ 9][0], &gui[ 9][1], &gui[ 9][2]);
		fscanf(fp,"Cancel	%i, %i, %i\n", &gui[10][0], &gui[10][1], &gui[10][2]);
		fscanf(fp,"Ongame	%i, %i, %i\n", &gui[11][0], &gui[11][1], &gui[11][2]);
	fclose(fp);


	int len=0, len_old=0; char *buf;
	if (!(fp=fopen("data/text/heros.txt", "r"))) return;
		fseek(fp, 0, SEEK_END);
		len=ftell(fp);
		fseek(fp, 0, SEEK_SET);
		buf=new char [len];
		fread(buf,len,1,fp);
	fclose(fp);

	for (int i=0; i<3; i++){
		len=strcspn(buf+len_old, "*");
		text[i]=new char[len+8];
		strncpy(text[i], buf+len_old, len);
		strcpy(text[i]+len, "\0");
		len_old+=len+11;
	}
	delete buf;
}

