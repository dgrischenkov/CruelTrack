

#include "Text.h"


Text::Text(char *text, int w, int h, gcn::ImageFont *font) : gcn::TextBox("")
{
	setSize(w, h);
	if (font) setFont(font);
	setEditable(false);
	setOpaque(false);
	setBorderSize(0);

	char *out_text=new char[strlen(text)*2];
	strcpy(out_text, "\0");
	gcn::Font *cfont=getFont( );
	int seek_old=0, len_old=0, seek_new=0, len_new=0;
	char buf1[1024], buf2[1024];
	strcpy(buf1, "\0"); strcpy(buf2, "\0");
	int seporator[255], i=0, n=0;
	int sep_row;

	while (strlen(text)>=seek_new) {
		do {
			if (!(strcmp(buf1+strlen(buf1)-1, "\n"))){
				strcat(out_text, buf1);
				strcpy(buf1, "\0");
				i=0;
			}
			len_old=len_new;
			seek_old=seek_new;
			len_new=strcspn(text+seek_new, " ");
			sep_row=strcspn(text+seek_new, "\n");
			if (sep_row<len_new) len_new=sep_row;
			strncat(buf1, text+seek_new, len_new+1);
			seek_new+=len_new+1;
			seporator[i]=strlen(buf1); i++;
		} while (cfont->getWidth(buf1)<w && strlen(text)>=seek_new);

		if (strlen(text)<=seek_new){
			strcat(out_text, buf1);
			break;
		}

		strcpy(buf1+strlen(buf1)-len_new-2, "\n");
		len_new=len_old;
		seek_new=seek_old;

		do {
			if ((i-2)==0) break;
			strcpy(buf2, buf1+seporator[n]);
			strcpy(buf1+seporator[n], "`\0");
			for (int m=n; m<i-2; m++) seporator[m]++;
			n++; if (n==i-2) n=0;
			strcat(buf1, buf2);
		} while (cfont->getWidth(buf1)!=w);

		strcat(out_text, buf1);
		strcpy(buf1, "\0");
		n=0; i=0;
	}

	setText (out_text);

}


void Text::keyPress (const gcn::Key &key)
{

}

