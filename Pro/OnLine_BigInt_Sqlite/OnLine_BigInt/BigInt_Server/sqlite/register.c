#include"sysutil.h"

int main(int argc, char *argv[])
{
	printf("Content-Type:text/html\n\n");
	char *method = getenv("REQUEST_METHOD");
	//printf("method = %s", method);

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

	//username=rocket&password=12345
	//printf("data = %s", data);
	char uname[MAX_NAME_SIZE] = {0};
	char upasswd[MAX_PASS_SIZE] = {0};

	char *p = strchr(data, '&');
	*p = '\0';   
	sscanf(data, "username=%s", uname);
	sscanf(p+1, "password=%s",upasswd);

	/////////////////////////////////////////////////////////////////////////////////
	sqlite3 *db;
	int rc = sqlite3_open(USER_DB, &db);
	if (rc)
	{
		printf("<h1 align=center>open database error.</h1>");
		exit(EXIT_FAILURE);
	}

	char sql[MAX_BUFFER_SIZE] = {0};
	sprintf(sql, "create table if not exists %s (user_name text PRIMARY KEY, user_passsword text)", USER_TABLE);
	rc = sqlite3_exec(db, sql, 0, 0, 0);
	if (rc != SQLITE_OK)
	{
		printf("<h1 align=center>exec sql error.</h1>");
		sqlite3_close(db);
		exit(EXIT_FAILURE);
	}

	memset(sql, 0, MAX_BUFFER_SIZE);
	sprintf(sql, "insert into %s values('%s', '%s')", USER_TABLE, uname, upasswd);
	rc = sqlite3_exec(db, sql, 0, 0, 0);
	if (rc != SQLITE_OK)
	{
		printf("<h1 align=center>insert sql data error.</h1>");
		sqlite3_close(db);
		exit(EXIT_FAILURE);
	}

	rc = sqlite3_close(db);
	if(rc)
	{
		printf("<h1 align=center>close database error.</h1>");
		exit(EXIT_FAILURE);
	}

	sleep(1);
	//Ò³Ãæ·µ»Ø
	FILE *fp = fopen("./htdocs/index.html", "r");
	if(NULL == fp)
	{
		printf("<h1 align=center>Return to page  Failure.</h1>");
		exit(EXIT_FAILURE);
	}

	char buf[MAX_BUFFER_SIZE] = {0};
	while(!feof(fp))
	{
		fgets(buf, MAX_BUFFER_SIZE, fp);
		printf(buf);
	}

	fclose(fp);
	
	return 0;
}