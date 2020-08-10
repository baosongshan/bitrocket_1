#include<iostream>
#include"sqlite3.h"
using namespace std;

#define USER_DB "user.db"
#define USER_TABLE "user"


#define MAX_NAME_SIZE   64
#define MAX_PASS_SIZE   128
#define MAX_BUFFER_SIZE 1024

void main()
{
	char data[] = "user=bss&password=6789";
	char uname[MAX_NAME_SIZE] = {0};
	char upasswd[MAX_PASS_SIZE] = {0};

	char *p = strchr(data, '&');
	*p = '\0';   
	sscanf(data, "username=%s", uname);
	sscanf(p+1, "password=%s",upasswd);

	sqlite3 *db;
	int rc = sqlite3_open(USER_DB, &db);
	if (rc)
	{
		printf("<h1 align=center>open database error.</h1>");
		exit(EXIT_FAILURE);
	}

	//¼øÈ¨
	char sql[MAX_BUFFER_SIZE] = {0};
	sprintf(sql, "select user_passsword from %s where user_name='%s'", USER_TABLE, uname);
	//sqlite3_exec(db, sql, 0, 0, 0);

	char **ppret;
	int row, col;
	sqlite3_get_table(db, sql, &ppret, &row, &col, 0);
	char password[MAX_PASS_SIZE] = {0};
	strcpy(password, ppret[1]);

	printf("password = %s", password);

	rc = sqlite3_close(db);
	if(rc)
	{
		printf("<h1 align=center>close database error.</h1>");
		exit(EXIT_FAILURE);
	}
}

/*
void main()
{
	//username=rocket&password=12345
	//printf("data = %s", data);
	
	char buffer[] = "username=rocket&password=12345";
	char uname[64] = {0};
	char upasswd[128] = {0};

	char *p = strchr(buffer, '&');
	*p = '\0';    //"username=rocket\0password=12345";
	sscanf(buffer, "username=%s", uname);
	sscanf(p+1, "password=%s",upasswd);
	///////////////////////////////////////////////////////////////////////

	sqlite3 *db;
	int rc = sqlite3_open("user.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}

	//create table user (user_name text, user_password text);
	char *zErrMsg;
	char sql[1024] = {0};
	sprintf(sql, "create table if not exists %s (user_name text PRIMARY KEY, user_passsword text)", "user");
	rc = sqlite3_exec(db, sql, 0, 0, 0);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Table created successfully\n");
	}

	memset(sql, 0, 1024);
	sprintf(sql, "insert into %s values('%s', '%s')", "user", uname, upasswd);
	rc = sqlite3_exec(db, sql, 0, 0, 0);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "insert SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Table insert successfully\n");
	}
	sqlite3_close(db);

	//Ò³Ãæ·µ»Ø
	FILE *fp = fopen("./htdocs/index.html", "r");
	if(NULL == fp)
	{
		printf("<h1> </h1>")
	}
}
*/