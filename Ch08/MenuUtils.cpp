#include <iostream>
#include <list>
#include <sstream>

using namespace std;

// #define T 

class MenuUtils{
private:
	list<pair<string,string> > cnt_list;

public:
	MenuUtils(){}

	MenuUtils& addPair(string idx,string value){
		cnt_list.push_back(pair<string,string>(idx,value));

		return *this;
	}

	MenuUtils& addPair(pair<string,string> pair_value){
		cnt_list.push_back(pair_value);

		return *this;
	}

	string toString(){
		list<pair<string,string> >::iterator iter = cnt_list.begin();
		ostringstream os;

		while(iter!=cnt_list.end()){
			os<<iter->first<<" => "<<iter->second<<"\n";
			iter++;
		}
		return os.str();
	}

	void clear(){
		cnt_list.clear();
	}
};

#ifdef T
int main(){
	MenuUtils mUtils;
	mUtils.addPair("1","hello").addPair("2","workd");

	cout<<mUtils.toString();
}
#endif