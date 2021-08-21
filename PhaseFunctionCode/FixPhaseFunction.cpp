#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	ifstream start("phaseFunction.txt");
	ofstream finish("phaseFunction.sca");
	char ch;
	int count=0;
	while(start.get(ch))
	{
	  if(ch==','){
	    ch =' ';
	    finish << ch;
	  }
	
	  finish << ch;
	}
	start.close();
	finish.close();
	return 0;
}
