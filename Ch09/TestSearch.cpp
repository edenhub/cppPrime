#include <iostream>
#include <bitset>

using namespace std;

inline void test01(string &str){
	int len = str.length();
	int tmp[128]={0};

	for(int i=0;i<len;i++){
		char ch = str[i];
		tmp[ch]++;
	} 

	for(int i=0;i<len;i++){
		char ch = str[i];
		if(tmp[ch] == 1)
			cout<<ch<<" ";
	}

	cout<<endl;
}

//00,01,10
enum statue{zero=0,one,more};

inline statue jugeStatue(bool first,bool second){
	if(!first && !second) return zero;
	else if(second) return one;
	else return more;
}

inline int posFirst(int i){
	return i*2;
}

inline int posSecond(int i){
	return i*2+1;
}

inline void test02(string &str){
	int len = str.length();
	bitset<256> tmp;

	for(int i=0;i<len;i++){
		char ch = str[i];
		int first = posFirst(ch),second = posSecond(ch);
		statue curr = jugeStatue(tmp[first],tmp[second]);
		switch(curr){
			case zero :{
				tmp[first] = 0;
				tmp[second] = 1;
				break;
			}
			case one : {
				tmp[first] = 1;
				tmp[second] = 0;
				break;
			}
		}
	}

	for(int i=0;i<len;i++){
		char ch = str[i];
		int first = posFirst(ch),second = posSecond(ch);
		statue curr = jugeStatue(tmp[first],tmp[second]);
		if(curr == one){
			cout<<ch<<" ";
		}
	}

}

int main(){
	string str;
	cin>>str;
	test01(str);
	cout<<"========================"<<endl;
	test02(str);

	cout<<endl<<"finish"<<endl;

	return 0;
}