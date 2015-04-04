#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void test01(){
	string str("hell world");
	cout<<str<<endl;
	string::size_type len = str.size();

	for(string::size_type idx = 0;idx!=len;idx++)
		cout<<str[idx]<<" ";
	cout<<endl;

	vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	for(vector<int>::iterator iter = vec.begin();iter!=vec.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;

	for(vector<int>::size_type i=0;i<vec.size();i++)
		cout<<vec[i];
	cout<<endl;

	const vector<int> &vec2 = vec;
	vector<int>::const_iterator iter = vec2.begin();
	for(;iter!=vec2.end();iter++)
		cout<<*iter;
	cout<<endl;
}

void test02(){
	const size_t len = 5;
	int ai[len] = {1,2,3,4,5};

	int *pia = ai;
	for(size_t i = 0;i<len;i++)
		cout<<*(pia+i);
	cout<<endl;

	char str1[] = "hello";
	char str2[] = {'h','e','l','l','o'};

	char *pt1 = str1;
	while(*pt1 != '\0'){
		cout<<*pt1;
		pt1++;
	}
	cout<<endl;
	for(size_t i=0;i<5;i++)
		cout<<*(str2+i);
	cout<<endl;

	cout<<strlen(str1)<<endl;
}

void test03(){
	size_t len = 5;
	int *ia = new int[len];
	delete(ia);

	int ma[][3] = {
		{1,2,7},
		{3,4,5}
	};

	int (*p)[3] = ma;
	cout<<(*p)[3];
}

int main(){

	test01();
	test02();
	test03();
}