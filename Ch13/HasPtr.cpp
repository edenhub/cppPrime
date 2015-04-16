#include <iostream>

using namespace std;

class HasPtr{
public:
	int *pt;
	int val;

	HasPtr(int *_pt,int _val):pt(new int(*_pt)),val(_val){}

	HasPtr(const HasPtr &_HasPtr):pt(new int(*_HasPtr.pt)),val(_HasPtr.val){}
	HasPtr& operator=(const HasPtr &_HasPtr){
		pt = new int(*_HasPtr.pt);
		val = _HasPtr.val;

		return *this;
	}

	~HasPtr(){
		delete pt;
	}
};

int main(){
	HasPtr *p1 =new HasPtr(new int(2),2);
	HasPtr p2 = *p1;

	cout<<"p1 : "<<*p1->pt<<endl;
	delete p1;
	cout<<"p2 : "<<*p2.pt<<endl;


	return 0;
}