#include <iostream>
#include "Consumer.cpp"

using namespace std;

class Saler{
private:
	int age;
	string name;
	string id;
	static string Department;
	static const int flag = 0;

	friend class Provider;
	// friend void Consumer::desplayDepartment();
public:
	explicit Saler():age(0),id("-"),name(""){}
	explicit Saler(int _age,string _name,string _id):age(_age),name(_name),id(_id){}

	void descript();
	void descript(ostream &os);

	string getDepartment(){
		return Saler::Department;
	}

	Saler& say(string &str,ostream &os);
	const Saler& say(string &str,ostream &os) const{
		return *this;
	}

	static void dump();

	void test() const {
		cout<<age<<endl;
	}
};

string Saler::Department = "Develop";

void Saler::descript(){
	cout<<"name : "<<name<<","
    	        <<"age : "<<age<<","
    	        <<"id : "<<id<<endl;
}

void Saler::descript(ostream &os){
	os<<"name : "<<name<<","
    	        <<"age : "<<age<<","
    	        <<"id : "<<id<<endl;
}

void Saler::dump(){
	cout<<"aaa"<<endl;
}

Saler& Saler::say(string &str,ostream &os){
	os<<name<<" say : "<<str<<endl;

	return *this;
}

class Provider{
private:
	string name;

public:
	Provider(){}
	Provider(string _name):name(_name){}

	static void desplayFlag(){
		cout<<Saler::flag<<endl;
	}
};

class Consumer{
private:
	string name;

public:
	Consumer(){}
	Consumer(string _name):name(_name){}

	void desplayDepartment(){
		// cout<<Saler::Department<<endl;
	}

};



int main(){
	Saler saler(23,"adam","0001");
	Provider::desplayFlag();
	Saler::dump();

	Saler *saler2 = new Saler(23,"adam","0001");
	saler2->descript();

	delete saler2;

	return 0;
}