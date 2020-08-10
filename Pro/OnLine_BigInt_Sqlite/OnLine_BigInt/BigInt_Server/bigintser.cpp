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

	//m=41431&n=41431&cmd=1
	std::string data = getenv("QUERY_STRING");

	//解析bt1
	int pos = data.find('=');
	const char *p = data.c_str() + pos + 1;
	while(*p>='0' && *p<='9')
	{
		bt1.push_front(*p-'0');
		p++;
	}

	//解析bt2
	pos = data.find('=', pos+1);
	p = data.c_str() + pos + 1;
	while(*p>='0' && *p<='9')
	{
		bt2.push_front(*p-'0');
		p++;
	}

	//解析操作符
	pos = data.find('=', pos+1);
	p = data.c_str() + pos + 1;
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