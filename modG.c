#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"

int cgiMain()
{

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

  char stuId[9] = "\0";
  char Cno[4] = "\0";
  char Grade [6] = "\0";
  int status = 0;
  status = cgiFormString("stuId",  stuId, 4);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get stuId error!\n");
		return 1;
	}
  status = cgiFormString("Cno",  Cno, 4);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Cno error!\n");
		return 1;
	}
  status = cgiFormString("Grade",  Grade, 4);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Grade error!\n");
		return 1;
	}

  int ret;
	char sql[128] = "\0";
	MYSQL *db;

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

  sprintf(sql, "update SC set Grade= %d where stuId = %d and Cno = %d", atoi(Grade),atoi(stuId),atoi(Cno));
  if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
  {
    fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
    mysql_close(db);
    return -1;
  }


  fprintf(cgiOut, "update Grade ok!\n");
	mysql_close(db);
	return 0;
}
