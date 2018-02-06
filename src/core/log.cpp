
/*
  Name: log.cpp
  Copyright: 
  Author: FLUF
  Date: 07.10.06 18:02
  Description: 
*/


#include "log.h"

void LogAdd(char *mes, int level)
{
	FILE *fp;

	bool flag_exist;
	if ( (fp=fopen("outlog.htm", "r"))==NULL ) flag_exist=false;
	else {
		flag_exist=true;
		fclose(fp);
	}

	if ( (fp=fopen("outlog.htm", "a"))==NULL ) return;

	if (!flag_exist) fprintf(fp, "<html>\n<body bgcolor=black>\n<br>\n"
		"<h2><font color=00ff00>OutLogZz of fxBrowZer</font></h2>\n<br>\n\n");

	fseek(fp, SEEK_SET, -3);
	if (level==0) fprintf(fp, "%s %s %s", "<font color=#00cc00>", mes, "</font><br>\n");
	if (level==1) fprintf(fp, "%s %s %s", "<font color=#ddbb22>", mes, "</font><br>\n");
	if (level==2) fprintf(fp, "%s %s %s", "<font color=#cc0000>", mes, "</font><br>\n");

	fclose(fp);
}

