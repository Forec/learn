#include <iostream>

using namespace std;

class test{
	private:
		int money;
		char name[21];
	protected:
		int length;
	public:
		int getsLength(void);
		void setMoney(int money);
};

void test::setMoney(int l){
	money = l;
}

int test::getsLength(void){
	return length;
}

class test2: test{
	public:
		void setLength(int);
		void setAddress(int);
		int getAddress(void);
	private:
		int address;
};

void test2::setLength(int l){
	length = l;
}

void test2::setAddress(int l){
	address = l;
}

int test2::getAddress(void){
	return address;
}


int main()
{
	test2 fun;
	fun.setAddress(12);
	cout << fun.getAddress() << endl;
	fun.setLength(123);
//	fun.setMoney(11);
//	cout << fun.getsLength() << endl;
	return 0; 
}
