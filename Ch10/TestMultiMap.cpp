#include <iostream>
#include <map>

using namespace std;

typedef pair<string,int> mType;
typedef multimap<string,int>::const_iterator mp_cit;
inline void test01(){
	multimap<string,int> mp;

	mp.insert(make_pair("idxA",2));
	mp.insert(mType("idxA",3));
	mp.insert(pair<string,int>("idxA",4));
	mp.insert(mType("idxB",5));

	pair<mp_cit,mp_cit> range_cit = mp.equal_range("idxA");
	while(range_cit.first != range_cit.second){
		cout<<range_cit.first->second<<endl;
		++range_cit.first;
	}

	cout<<"======================="<<endl;

	mp_cit upper = mp.upper_bound("idxA");
	mp_cit lower = mp.lower_bound("idxA");

	while(lower != upper){
		cout<<lower->second<<endl;
		++lower;
	}
}

int main(){
	test01();

	return 0;
}