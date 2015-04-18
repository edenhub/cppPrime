#include <iostream>

using namespace std;

enum Department{Dev,Salse,HR};

class Employ{
private:
    string id;
    Department depart;
protected:
    int age;
public:
    Employ(){}
    Employ(string _id,int _age,Department _depart):id(_id),age(_age),depart(_depart){}

    virtual void work(){
        cout<<"Employ :: not thing yet"<<endl;
    }

    virtual ~Employ(){}

};

enum Skill{Java,CPP,C};
class Developer:public Employ{
private:
    Skill skill;
    int age;

public:
    Developer():Employ(){}
    Developer(string _id,int _age,Department _depart,Skill _skill):Employ(_id,_age,_depart),skill(_skill){}

    void work(){
        cout<<"Developer :: Coding ...."<<Employ::age<<endl;
    }

    virtual ~Developer(){
    }

};

class Specialer:private Employ{
private:
    string securt;
    int age;

public:
    Specialer():Employ(){}
    Specialer(string _id,int _age,Department _depart,string _securt):Employ(_id,_age,_depart),securt(_securt){}

    void work(){
        cout<<"Specialer :: Viewing ... "<<endl;
    }

    void work(string target){
        cout<<"Specialer :: Viewing target : "<<target<<endl;
    }

    int getAge(){
        return age;
    }

    void setAge(int age){
        this->age = age;
    }

    virtual ~Specialer(){}
};

int main(){
    Employ  *adam = new Developer("001",23,Dev,Java);
    adam->work(); 

    Specialer *sadam = new Specialer("002",23,HR,"Watch");
    sadam->work();
    return 0;
}