#include <iostream>
using namespace std;

int main()
{
	int a = 1;
	try {
		if ( a!=2 ){
			throw 2;
		}
	}catch(const int err){
		cout << err << endl;
	} 
	return 0;
} 
