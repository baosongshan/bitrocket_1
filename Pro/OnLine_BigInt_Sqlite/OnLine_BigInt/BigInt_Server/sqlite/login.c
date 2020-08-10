#include"sysutil.h"


int main(int argc, char *argv[])
{
	printf("Content-Type:text/html\n\n");
	printf("<p>AAAAAAAAAAAAAAAAA<p>");

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

	printf("data = %s", data);

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

	printf("row = %d, col = %d", row, col);

	char password[MAX_PASS_SIZE] = {0};
	//for(int i=1; i<=row; ++i)
	//strcpy(password, *ppret[1])

	//printf("password = %s", *ppret[1]);
	

	rc = sqlite3_close(db);
	if(rc)
	{
		printf("<h1 align=center>close database error.</h1>");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
