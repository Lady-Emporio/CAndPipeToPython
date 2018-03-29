#include <stdio.h>
#include <errno.h>
#include <iostream>
#include <string>
#define BUF_SIZE 50
using namespace std;
int main(int argc, char * argv[])
{
  FILE * f;
  FILE * o;
  int len;
  char buf[BUF_SIZE];
  if (argc != 2)
  {
     printf("использование: makelog \"<command>\"\n");
     return -1;
  }
//   f = popen(argv[1], "r");
//   g++ f.cpp -std=c++11 && ./a.out "python3 f.py"
  string com="python3 f.py";
  com+=" '";
  com+=argv[1];
  com+="'";
  f = popen(com.c_str(), "r");
  if (f == NULL)
  {
    perror("ошибка:\n");
    return -1;
  }
  string result;
  while ((len = fread(buf, 1, BUF_SIZE, f)) != 0)
  {
		result+=buf;
  }
	int TableRow=stoi(result);
	cout<<"This is int: "<<TableRow<<endl;
	pclose(f);
	return 0;
} 
