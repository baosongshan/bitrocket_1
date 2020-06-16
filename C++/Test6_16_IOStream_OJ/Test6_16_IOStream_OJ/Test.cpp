#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

void main()
{
	string str = "414791";
	cout<<atoi(str.c_str())<<endl;  //const char *

	cout<<stoi(str)<<endl;
}

/*
void main()
{
	stringstream sstream; //空对象

	sstream << "first" << " " << "string,"; //first string second string

	sstream << " second string";
	cout << "strResult is: " << sstream.str() << endl;
	// 清空 sstream
	sstream.str("");
	sstream << "third string";
	cout << "After clear, strResult is: " << sstream.str() << endl;
}

/*
void main()
{
	string str = "47194714811";
	stringstream sstream;
	sstream<<str;

	int value;
	sstream>>value;
	cout<<"value = "<<value<<endl;
}

/*
void main()
{
	int a = 47194140;
	stringstream sstream;
	sstream<<a;  //a--> stringstream

	string str;
	sstream>>str; //stringstream -->str
	cout<<"str = "<<str<<endl;


}


/*
void main()
{
	char *str = "4719478502850201";
	cout<<"str = "<<str<<endl;
	int value = atoi(str);
	cout<<"value = "<<value<<endl;
}

/*
struct ServerInfo
{
	char _ip[32];  // ip
	int  _port;    // 端口
};

class ConfigManager
{
public:
	ConfigManager(string str):_configfile(str)
	{
		ReadSerInfo();
	}
	~ConfigManager()
	{
		WriteSerInfo();
	}
public:
	void ReadSerInfo()
	{
		ifstream ifile;
		ifile.open(_configfile.c_str(), ios::in);
		if(!ifile)
		{
			cerr<<"Open File Error."<<endl;
			exit(1);
		}

		ifile>>ser_info._ip>>ser_info._port;

		ifile.close();
	}
	void WriteSerInfo()
	{
		ofstream ofile;
		ofile.open(_configfile.c_str(), ios::out);
		if(!ofile)
		{
			cerr<<"Open File Error."<<endl;
			exit(1);
		}

		ofile<<ser_info._ip<<" "<<ser_info._port;

		ofile.close();
	}
	void set_info(string ip, int port)
	{
		strcpy(ser_info._ip, ip.c_str());
		ser_info._port = port;
	}
public:
	void show_info()const
	{
		cout<<"ip = "<<ser_info._ip<<endl;
		cout<<"port = "<<ser_info._port<<endl;
	}
private:
	string _configfile;
	ServerInfo ser_info;
};

void main()
{
	ConfigManager cfmgr("bit.conf");
	cfmgr.show_info();

	cfmgr.set_info("10.182.1.212", 9999);
	cfmgr.show_info();

}

/*
//C++ read
void main()
{
	vector<int> iv(10);

	ifstream ifile("Test4.txt", ios::in|ios::binary); //构造方法

	if(!ifile)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}

	ifile.read((char*)&iv[0], sizeof(int)*10);

	ifile.close();
}

/*
//C++ write-bin
void main()
{
	vector<int> iv = {12,23,34,45,56,67,78,89,90,100};

	ofstream ofile("Test4.txt", ios::out|ios::binary); //"wb"
	if(!ofile)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}
	
	ofile.write((const char*)&iv[0], sizeof(int)*iv.size());

	ofile.close();
}


/*
//C read-bin
void main()
{
	vector<int> iv(10);
	FILE *fp = fopen("Test3.txt", "rb");
	if(NULL == fp)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}

	fread(&iv[0], sizeof(int), 10, fp);

	fclose(fp);
}
/*
//C write-bin
void main()
{
	vector<int> iv = {12,23,34,45,56,67,78,89,90,100};
	FILE *fp = fopen("Test3.txt", "wb");
	if(NULL == fp)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}

	fwrite(&(iv[0]), sizeof(int), iv.size(), fp);

	fclose(fp);
}

/*
//文本文件 读写方式
//C++ read
void main()
{
	vector<int> iv;
	//ifstream ifile;
	//ifile.open("Test2.txt", ios::in);

	ifstream ifile("Test2.txt", ios::in); //构造方法

	if(!ifile)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}

	int val;
	for(int i=0; i<10; ++i)
	{
		ifile>>val;
		iv.push_back(val);

	}

	ifile.close();
}

/*
//C read
void main()
{
	vector<int> iv;
	FILE *fp = fopen("Test1.txt", "r");
	if(NULL == fp)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}

	int val;
	//for(int i=0; i<10; ++i)
	while(!feof(fp))
	{
		fscanf(fp, "%d", &val);
		iv.push_back(val);
	}

	fclose(fp);
}

/*
//C++ write
void main()
{
	vector<int> iv = {12,23,34,45,56,67,78,89,90,100};

	ofstream ofile;
	ofile.open("Test2.txt", ios::out);
	if(!ofile)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}
	for(const auto &e : iv)
		ofile<<e<<" ";

	ofile.close();
}

/*
//C write
void main()
{
	vector<int> iv = {12,23,34,45,56,67,78,89,90,100};
	FILE *fp = fopen("Test1.txt", "w");
	if(NULL == fp)
	{
		cerr<<"Open File Error."<<endl;
		exit(1);
	}

	for(const auto &e : iv)
		fprintf(fp, "%d ", e);

	fclose(fp);
}

/*
void main()
{
	cout<<"HelloBit."<<endl;
}
*/