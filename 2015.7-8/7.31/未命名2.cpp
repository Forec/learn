#include <iostream>
#include<fstream>
#include <cstring>
using namespace std;

class fore{
	private:
		int next;
		int pre;
		char *s;
	public:
		fore(){
			next = 0;
			pre = 0;
			s =new char[1];
			s[0] = '\0';
		}
		fore(int);
		fore(const int n,const int re,const char *p){
			next = n;
			pre = re;
			int len = strlen(p);
			s = new char[len];
			strcpy(s,p);
		}
		fore(fore&);
		~fore();
		fore operator+(const fore&);
		fore& operator=(const fore&);
		friend fore operator*(const int ,fore&);
		bool operator==(const fore&);
		friend ostream& operator<<(ostream& output,const fore& rhs);
		friend istream& operator>>(istream& input,fore& rhs);
};

fore::fore(fore&rhs){
	next=rhs.next;
	pre=rhs.pre;
	s = new char[strlen(rhs.s)];
	strcpy(s,rhs.s);
}

fore::fore(int len){
	next = 0;
	pre = 0;
	s = new char[len];
}

fore::~fore(){
	delete []s;
}

fore operator*(const int n,fore& rhs){
	rhs.pre*=n;
	rhs.next*=n;
	int len = n * strlen(rhs.s);
	char temp[strlen(rhs.s)+1];
	strcpy(temp,rhs.s);
	delete[] rhs.s;
	rhs.s = new char[len+1];
	strcpy(rhs.s,temp);
	for (int i = 0 ; i < n-1 ; i++){
		strcat(rhs.s,temp);
	}
	return rhs;
}

fore& fore::operator=(const fore& rhs){
	if (this != &rhs){
		delete[] s;
		s = new char[strlen(rhs.s)+1];
		strcpy(s,rhs.s);
		pre = rhs.pre;
		next = rhs.next;
	}
	return *this;
}

fore fore::operator+(const fore &a){
	fore ne;
	ne.next = next + a.next;
	ne.pre = pre + a.pre;
	int len;
	if ( s == NULL && a.s == NULL )
		len = 0;
	else if ( s== NULL)
		len = strlen(a.s);
	else if ( a.s== NULL)
		len = strlen(s);
	else 
		len= strlen(s)+ strlen(a.s);
	len++;
	ne.s = new char[len];
	strcpy(ne.s,s);
	strcat(ne.s,a.s);
	return ne;
}

ostream& operator<<(ostream& output,const fore&rhs){
	output << rhs.pre << " " << rhs.next << " " << rhs.s << endl;
	return output;
}


istream& operator>>(istream& input,fore&rhs){
	input >> rhs.pre >> rhs.next >> rhs.s;
	return input; 
}

bool fore::operator==(const fore& rhs){
	if ( s==NULL )
		if ( rhs.s != NULL)
			return false;
	if (s!=NULL && rhs.s != NULL && strcmp(s,rhs.s)!=0)	
		return false;
	else if (next == rhs.next && pre == rhs.pre)
		return true;
	return false;
}

int main(){
/*	ifstream afile;
	afile.open("f.exe",ios::in|ios::binary);
	cout << afile.is_open() << endl;
	long l,m;
	l = afile.tellg();
	char s;
	while (!afile.eof()){
		afile >> s;
	}
	afile.seekg(1,ios::end);
	m = afile.tellg();
	cout << m-l << endl;
	afile.close();
	cout << endl << endl;*/
	fore a(10,2,"test1");
	int n;
	fore *bt = new fore(100);
	cin >> *bt >> n;
	cout << n << n*(*bt);
	return 0; 
} 
