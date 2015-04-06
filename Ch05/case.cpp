#include <iostream>

using namespace std;

void test(){
	double dVal = 97.3;
	char cVal1 = (char)dVal;
	char cVal2 = static_cast<char>(dVal);

	cout<<cVal1<<endl;
	cout<<cVal2<<endl;

int main(){
	test();
}