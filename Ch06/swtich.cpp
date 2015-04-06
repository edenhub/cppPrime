#include <iostream>

using namespace std;

void test(){
	int iVal = 4;

	switch(iVal){
		case 1 : {
			int mInt = 3;
			
		}
		break;
		case 4 :
			{
				cout<<"here"<<endl;
			}
			break;
		default :
			{cout<<"default"<<endl;}
	}
}

int main(){

	test();

}