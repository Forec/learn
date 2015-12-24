#include <iostream>
#include <csignal>
#include <cstdlib>
#include <fstream>
#include <windows.h>

using namespace std;

void _handle(int signum){
	ofstream output;
	output.open("output.txt" ,  ios::out | ios::trunc) ;
	output << "Interrupt signal "<< signum << endl;
	output.close();
	exit(signum);
} 

int main()
{
	int i=0;
	signal(SIGINT,_handle);
	while (++i){
		cout << "going to.. " << i << endl;
		if (i == 3){
			raise(SIGINT);
		} 
		Sleep(1000);
	}
	return 0;
}
