 #include <iostream>
#include <cstddef>

using namespace std;

void swap1(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int *&a,int *&b){
	int *tmp = a;
	a = b;
	b = tmp;
}

void test03(int *ai, size_t len){
	for(size_t i = 0;i<len;i++)
		cout<<*ai++<<endl;
}

void test02(const int a){
	cout<<a<<endl;
}

inline void simpleFun(){
	cout<<"simple"<<endl;
}

void test04(){
	simpleFun();
}

void test01(){
	int a=5,b=3;
	int *pa = &a,*pb = &b;
	swap2(pa,pb);

	cout<<*pa<<" : "<<*pb<<endl;	
}

int getNum1(int a){
	return a;
}

void test05(){
	 int (*pf1)(int);
	pf1 = getNum1;

	cout<<pf1(3);
}




int main(){

	test01();
	test02(4);
	int ai[] = {1,2,3};
	test03(ai,3);
	test04();
	test05();
}