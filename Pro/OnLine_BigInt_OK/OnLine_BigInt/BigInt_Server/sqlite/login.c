#include"sysutil.h"


int main(int argc, char *argv[])
{
	printf("Content-Type:text/html\n\n");

	char *method = getenv("REQUEST_METHOD");
	char data[MAX_BUFFER_SIZE] = {0};
	if(strcasecmp(method, "GET") == 0)
	{
		char *pret = getenv("QUERY_STRING");
		strcpy(data, pret);
	}
	else if(strcasecmp(method, "POST") == 0)
	{
		int len = atoi(getenv("CONTENT_LENGTH"));
		fgets(data, len+1, stdin);
	}
	else
	{
		printf("<h1 align=center>Request Method Error</h1>");
		exit(EXIT_FAILURE);
	}

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


	//获取用户相对应的密码
	char password[MAX_PASS_SIZE] = {0};
	char sql[MAX_BUFFER_SIZE] = {0};
	sprintf(sql, "select user_password from %s where user_name='%s'", USER_TABLE, uname);

	char **ppret;
	int row, col;
	sqlite3_get_table(db, sql, &ppret, &row, &col, 0);
	if(row != 0)
		strcpy(password, ppret[1]);
	sqlite3_free_table(ppret);

	rc = sqlite3_close(db);
	if(rc)
	{
		printf("<h1 align=center>close database error.</h1>");
		exit(EXIT_FAILURE);
	}
	
	//鉴权
	if(row==0 || strcmp(upasswd, password) != 0)
	{
		//鉴权失败
		printf("<meta http-equiv=refresh content=3;url=index.html>"); 
		printf("<h1 align=center>User Login Failure. Please Try Later.</h1>");
	}
	else
	{
		//鉴权成功
		printf("<meta http-equiv=refresh content=3;url=bigintcalc.html>"); 
		printf("<h1 align=center>User Login Success.</h1>");
	}

	return 0;
}
