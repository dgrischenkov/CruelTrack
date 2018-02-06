
/*
  Name: config.cpp
  Copyright: 
  Author: FLUF
  Date: 07.10.06 17:52
  Description: 
*/

#pragma warning (disable : 4267)
#pragma warning (disable : 4800)

#include "config.h"

Config::Config( )
{
	FILE *fp;
	if ( (fp=fopen("config.ini", "r"))==NULL ){
		LogAdd("bool Config::Config( ) >> Файл"
			" config.ini не могу открыть на чтение", 2);
		return;
	}

	fseek(fp, 0, SEEK_END);
	long len=ftell(fp);
	char *buf=new char[len];
	fseek(fp, 0, SEEK_SET);

	fread(buf, len, 1, fp);
	fclose(fp);

	LogAdd("<hr>Файл conf.ini в оперативную память загружен", 0);

	int seek=0;
	char ch;
	int seek_temp;
	char command[16];
	char ch_val[5];
	int int_val;
	int row=0;
	char ch_row[255];
	char outmes[255];
	int mes_level=0;

	while ( seek < len-row ) {

		ch=buf[seek];

		if (ch=='#'){
			seek+=strcspn(&buf[seek], "\n")+1;
			row++;
		} else if (ch=='\n'){
			seek++;
			row++;
		} else if (ch==' '){
			seek++;
		} else {
			seek_temp=strcspn(&buf[seek], " ");
			if (seek_temp>15){
				strcpy(outmes, "Ошибка синтаксиса в фале конфигурации conf.ini в строке ");
				itoa(row, ch_row, 10);
				strcat(outmes, ch_row);
				LogAdd(outmes, 2);
				return;
			}

			strncpy(command, &buf[seek], seek_temp);
			command[seek_temp]='\0';

			seek+=seek_temp+1;
			seek_temp=strcspn(&buf[seek], "\n");
			row++;

			strncpy(ch_val, &buf[seek], seek_temp);
			ch_val[seek_temp]='\0';
			int_val=atoi(ch_val);
			if ( int_val<-32768 || int_val>32768 ){
				strcpy(outmes, "Ошибка: неправильное значение в фале конфигурации conf.ini в строке ");
				itoa(row, ch_val, 10);
				strcat(outmes, ch_val);
				LogAdd(outmes, 2);
				return;
			}

			if ( !strcmp(command, "FULLSCREEN") ) screen_full=(bool)int_val;
			else if ( !strcmp(command, "STENCIL") ) screen_stencil=(bool)int_val;
			else if ( !strcmp(command, "VSYNC") ) screen_vsync=(bool)int_val;
			else if ( !strcmp(command, "WIDTH") ) screen_w=int_val;
			else if ( !strcmp(command, "HEIGHT") ) screen_h=int_val;
			else if ( !strcmp(command, "BPP") ) screen_bpp=int_val;
			else mes_level=1;
			
			strcpy(outmes, "-->");
			itoa(row, ch_row, 10);
			strcat(outmes, ch_row);
			strcat(outmes, ": ");
			if (mes_level==1) strcat(outmes, "неизвестный параметр ");
			strcat(outmes, command);
			strcat(outmes, " ");
			strcat(outmes, ch_val);
			LogAdd(outmes, mes_level);
			mes_level=0;

			seek+=seek_temp+1;
		}
	}

	LogAdd("Обработка файла конфигурации закончена<hr>", 0);
}


Config::~Config( )
{
    
}
