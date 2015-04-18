#include <iostream>

using namespace std;

class Saler{
private:
    string id;
    int age;

    friend Saler operator+(const Saler&,const Saler&);
    friend Saler operator-(const Saler&,const Saler&);
    friend ostream& operator<<(ostream&,const Saler&);
    friend bool operator==(const Saler&,const Saler&);

public:
    Saler():id(""),age(0){}
    Saler(string _id,int _age):id(_id),age(_age){}

    Saler(const Saler& _saler):id(_saler.id),age(_saler.age){}
    Saler& operator=(const Saler& _saler){
        id = _saler.id;
        age = _saler.age;

        return *this;
    }

    Saler& operator+=(const Saler& _saler){
        age += _saler.age;

        return *this;
    }

    Saler& operator++(){
        age += 1;

        return *this;
    }

    Saler operator++(int){
        Saler saler = Saler(*this);
        age+=1;

        return saler;
    }

    Saler& operator--(){
        age-=1;
        return *this;
    }

    Saler operator--(int){
        Saler saler = Saler(*this);
        age-=1;

        return saler;
    }

    bool operator<(const Saler& _saler){
        if(id < _saler.id) return true;
        else if(id ==_saler.id){
            return age<_saler.age;
        }else{
            return false;
        }
    }

    operator string() const{
        return id;
    }

    
};

    bool operator==(const Saler& _s1,const Saler& _s2){
        return (_s1.id == _s2.id) && (_s1.age == _s2.age);
    }

    // bool operator!=(const Saler& _saler){
    //     return !operator==(_saler);
    // }

    // bool operator>(const Saler& _saler){
    //     return !operator<(_saler);
    // }

    // bool operator<=(const Saler& _saler){
    //     return true;
    // }

    // bool operator>=(const Saler& _saler){
    //     return true;
    // }

Saler operator+(const Saler& _s1,const Saler& _s2){
    Saler saler(_s1.id+_s2.id,_s1.age+_s2.age);

    return saler;
}

Saler operator-(const Saler& _s1,const Saler& _s2){
    Saler saler("",_s1.age - _s2.age);

    return saler;
}

ostream& operator<<(ostream& os,const Saler& _saler){
    os<<_saler.id<<" : "<<_saler.age<<endl;

    return os;
}


void dumpSaler(const string& str){
    cout<<str<<endl;

}
int main(){

    Saler s1("1",23),s2("2",24),s3("3",17);

    cout<<s1;
    s1 += s2;
    Saler s4 = s2 + s3;

    cout<<s1<<s4;
    bool res = s1 == s2;
    cout<<res<<endl  ;

    dumpSaler(s1);

    return 0;
}