#include <bitset>
#include <iostream>
#include <string>

using namespace std;

#define TEST 1

void test(){
	bitset<33> set1;
	bitset<33> set2((long)3);
	string str("000011100");
	bitset<33> set3(str);

	int size = set1.size();

	for(int i=0;i<size;i++){
		cout<<set1[i]<<" ";
	}

	cout<<endl;

	for(int i=0;i<size;i++){
		cout<<set2[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<size;i++){
		cout<<set3[i]<<" ";
	}

}

int main(){

	#ifdef TEST
		test();
	#endif
}

