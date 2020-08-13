#include"./BigInt/bigint.h"
#include<string>

typedef enum{ADD=1, SUB, MUL, DIV, MOD} OPER;

void Html_Header()
{
	printf("Content-Type: text/html; charset=utf-8\n\n");
	printf("<title>Bit OnLine BigInt</title>");
	printf("<H1 align=center>WelCome to Bit BigInt abc</H1>");
}


void Data_Handler(BigInt &bt, BigInt &bt1, BigInt &bt2, OPER &op)
{
	bt.clear();
	bt1.clear();
	bt2.clear();

	char *method = getenv("REQUEST_METHOD");
	char data[2048] = {0};
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

	char *p = strchr(data, '&');
	*p = '\0';

	char *q = strchr(data, '=');
	q++;

	//m=41431&n=41431&cmd=1
	//std::string data = getenv("QUERY_STRING");

	//解析bt1
	while(*q != '\0')
	{
		bt1.push_front(*q-'0');
		q++;
	}

	q = p+3;
	p = strchr(p+1, '&');
	*p = '\0';

	//解析bt2
	while(*q != '\0')
	{
		bt2.push_front(*q-'0');
		q++;
	}

	//解析操作符
	p = strchr(p+1, '=');
	p++;
	if(*p == '1')
		op = ADD;
	if(*p == '2')
		op = SUB;
	if(*p == '3')
		op = MUL;
	if(*p == '4')
		op = DIV;

	if(op == ADD)
		bt = bt1 + bt2;
	if(op == SUB)
		bt = bt1 - bt2;
	if(op == MUL)
		bt = bt1 * bt2;
	if(op == DIV)
		bt = bt1 / bt2;
}

void Data_Show(const BigInt &bt, const BigInt &bt1, const BigInt &bt2, OPER oper)
{
	printf("<br>");
	
	//输出bt1
	printf("<div style='word-wrap:break-word;font-size:30px;fontweight:blod;' align=center>bt1=");
	for (int i = bt1.size(); i >= 1; --i)
		printf("%d", bt1[i]);
	printf("<br>");

	//输出运算符
	if (oper == ADD)
		printf("+<br>");
	else if (oper == SUB)
		printf("-<br>");
	else if (oper == MUL)
		printf("*<br>");
	else if (oper == DIV)
		printf("/<br>");

	//输出bt2
	printf("bt2=");
	for (int i = bt2.size(); i >= 1; --i)
		printf("%d", bt2[i]);
	printf("<br>");


	//输出结果
	printf("||<br>");
	for (int i = bt.size(); i >= 1; --i)
		printf("%d", bt[i]);
	printf("</div>");

	//页面返回
	printf("<div align=center>");
	printf("<a href=bigintcalc.html>");
	printf("<input type=button value=Continue style=width:200px;/>");
	printf("</a>");
	printf("</div>");
}

int main(int argc, char *argv[])
{
	Html_Header();

	BigInt bt, bt1, bt2;
	OPER op;
	Data_Handler(bt, bt1, bt2, op);

	Data_Show(bt, bt1, bt2, op);

	return 0;
}