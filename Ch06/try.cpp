#include <iostream>
#include <stdexcept>
#include <exception>
#include <cassert>

using namespace std;

void test01(){
	try{
		throw  "exception";
	}catch(const char* e){
		cout<<"exception : "<<e<<endl;
	}
}

void test02(){
	#ifndef NDEBUG
		cout<<"not define"<<endl;
	#endif
}

void test03(){
	assert(3<2);

	cout<<"next"<<endl;
}

int main(){
	test01();
	test02();
	test03();
}