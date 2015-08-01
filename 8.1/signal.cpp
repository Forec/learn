#include <iostream>
#include <csignal>
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

void _handle(int signum){
	ofstream sfile;
	sfile.open("output.txt",ios::out|ios::trunc);
	sfile << "test the signal " << signum << endl;
	sfile.close();
	exit(signum);
}

int main()
{
	signal(SIGINT,_handle);
	while (1){
		cout << "this is ..." << endl;
		Sleep(1000);
	}
	return 0;
}
