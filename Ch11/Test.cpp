#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void dump(const vector<string> &vet){
	vector<string>::const_iterator cit  = vet.begin();

	while(cit != vet.end())
		cout<<*cit++<<endl;
}

bool isSorter(const string &fir,const string &sec){
	return fir.length() <= sec.length();
}

bool isGT6(const string &fir){
	return fir.size() >=6;
}

void test01(){
	cout<<"input the file to open : "<<endl;
	string fileName;
	cin>>fileName;
	ifstream fin(fileName.c_str());
	istream_iterator<string> strin(fin),streof;
	vector<string> words(strin,streof);

	vector<string>::iterator iter=words.begin();
	sort(iter,words.end());

	vector<string>::iterator end_it =  unique(iter,words.end());
	words.erase(end_it,words.end());


	sort(words.begin(),words.end(),isSorter);
	vector<string>::size_type cnt = count_if(words.begin(),words.end(),isGT6);

	dump(words);
	cout<<cnt<<endl;
	cout<<*(words.begin()+words.size()-cnt)<<endl;
}

void test02(){
	cout<<"input the file to open : "<<endl;
	string fileName;
	cin>>fileName;
	ofstream ofs(fileName.c_str(),fstream::app);
	ostream_iterator<string> strout(ofs,"\n");
	istream_iterator<string> strin(cin),streof;

	while(strin!=streof){
		*strout++ = *strin++;
	}
}

class MyClazz{
public:
	int age;
	string name;
};

int main(){
	test01();
	// test02();

	return 0;
}