#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"

int cgiMain()
{

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

	char name[32] = "\0";
	char age[16] = "\0";
	char stuId[100] = "\0";
	char Ssdept[20] = "\0";
	char Ssex[10] = "\0";

	//课程信息
	/*char Cno[4] = "\0";
	char Cname[40] = "\0";
	char Credit[6] = "\0";*/
	int status = 0;

	status = cgiFormString("name",  name, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get name error!\n");
		return 1;
	}

	status = cgiFormString("age",  age, 16);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get age error!\n");
		return 1;
	}

	status = cgiFormString("stuId",  stuId, 100);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get stuId error!\n");
		return 1;
	}

	status = cgiFormString("Ssdept", Ssdept,20);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Ssdept error!\n" );
		return 1;
	}

	status = cgiFormString("Ssex",  Ssex, 10);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Ssex error!\n");
		return 1;
	}




	/*status = cgiFormString("Cno",  Cno, 4);
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
	status = cgiFormString("Credit",  Credit, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get Credit error!\n");
		return 1;
	}*/

	//fprintf(cgiOut, "name = %s, age = %s, stuId = %s\n", name, age, stuId);

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



	/*strcpy(sql, "create table stu(id int not null primary key, name varchar(20) not null, age int not null,Ssdept varchar(20) not null,Ssex varchar(10) not null)");
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		if (ret != 1)
		{
			fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
			mysql_close(db);
			return -1;
}*/


	//添加课程信息
	/*sprintf(sql, "insert into Course values(%d,'%s',%d)",atoi(Cno),Cname,atoi(Credit));
	if (mysql_real_query(db, sql, strlen(sql) + 1) != 0)
	{
		fprintf(cgiOut, "%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}*/


	fprintf(cgiOut, "add student ok!\n");
	mysql_close(db);
	return 0;
}
