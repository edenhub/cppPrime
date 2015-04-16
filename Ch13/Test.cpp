#include <iostream>

using namespace std;

class param1{
public:
	~param1(){
		cout<<"param1"<<endl;
	}
};

class param2{
public:
	~param2(){
		cout<<"param2"<<endl;
	}
};

class Saler{
private:
	int age;
	string name;
	int id;

public:
	Saler(){}
	Saler(int _age,string _name,int _id):age(_age),name(_name),id(_id){}

	Saler(const Saler &_saler):age(_saler.age),name(_saler.name),id(_saler.id){}
	Saler& operator=(const Saler &_saler){
		age = _saler.age;
		name = _saler.name;
		id = _saler.id;

		return *this;
	}

	~Saler(){
		cout<<"Destrop "<<id<<endl;
	}

	void toString(){
		cout<<"id : "<<id<<" age : "<<age<<" ,  name"<<name<<endl;
	}

	void setId(int id){
		Saler::id = id;
	}

	param1 p1;
	param2 p2;

};



int main(){
	Saler adam(23,"adam",1);
	Saler adamC = adam;
	adamC.setId(2);

	adam.toString();
	adamC.toString();

	Saler *adamP = new Saler(adam);
	adamP->setId(3);
	adamP->toString();
	delete adamP;

	return 0;
}