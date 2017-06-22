#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"

char * headname = "head.html";
char * footname = "footer.html";


int cgiMain()
{
	FILE * fd;
	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");


  char Cno[4] = "\0";
  char Cname[40] = "\0";
  //char Cpno[4] = "\0";
  char Credit[6] = "\0";
  int status = 0;
	char ch;

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");
	if(!(fd = fopen(headname, "r"))){
		fprintf(cgiOut, "Cannot open file, %s\n", headname);
		return -1;
	}
	ch = fgetc(fd);

	while(ch != EOF){
		fprintf(cgiOut, "%c", ch);
		ch = fgetc(fd);
	}
fclose(fd);

  status = cgiFormString("Cno",  Cno, 4);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Cno error!\n");
		return 1;
	}
	status = cgiFormString("Cname",  Cname, 40);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Cname error!\n");
		return 1;
	}
  /*status = cgiFormString("Cpno",  Cpno, 4);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Cpno error!\n");
		return 1;
	}*/
	status = cgiFormString("Credit",  Credit, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Credit error!\n");
		return 1;
	}


  int ret;
	char sql[128] = "\0";
	MYSQL *db;


  //初始化
	db = mysql_init(NULL);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_init fail:%s\n", mysql_error(db));
		return -1;
	}

	//连接数据库
	db = mysql_real_connect(db, "127.0.0.1", "root", "123456", "stu",  3306, NULL, 0);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_real_connect fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}

  sprintf(sql, "insert into Course values(%d,'%s',%d)",atoi(Cno),Cname,atoi(Credit));
  if (mysql_real_query(db, sql, strlen(sql) + 1) != 0)
  {
    fprintf(cgiOut, "%s\n", mysql_error(db));
    mysql_close(db);
    return -1;
  }



  fprintf(cgiOut, "add Course ok!\n");
	mysql_close(db);
	return 0;
}
