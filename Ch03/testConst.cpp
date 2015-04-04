#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define TEST 0

void test(){
	int a=5;
	const int b =a;

	cout<<b<<endl;

	const string str("hello");
	const string cStr = str;

	cout<<cStr<<endl;

	int &ri = a;
	const int &ri2 = a;

	const int ci = 9;
	const int &ri3 = ci;

	int &ri4 = ri;
	cout<<ri4<<endl;
	//

	int *pi = &a;
	const int *pi2 = &b;
	const int *pi3 = &a;

	cout<<"const point<"<<endl;
	int *const pi4 = &a;
	const int *pi5 = &a;

	cout<<*pi4<<endl;
	cout<<*pi5<<endl;

	int c = 10;

	// pi4 = &c;
	pi5 = &c;

	cout<<*pi4<<endl;
	cout<<*pi5<<endl;
	// cout<<*pi4<<endl;


	int *pp = new int(4);
	// cout<<*pp<<endl;
	delete pp;
}

int main(){
	#ifdef TEST 
		test();
	#endif
}