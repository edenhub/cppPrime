#include <iostream>

using namespace std;

void test01(int a){
    if(a > 0)
        throw "error";
    std::cout<<"end"<<std::endl;
}

struct myE{
    string msg;

    myE(){}
    myE(string _msg):msg(_msg){}

    ~myE(){
        std::cout<<"d myE"<<std::endl;
    }
};

struct newE:myE{
    string msgE;

    newE(){}
    newE(string _msg):myE(_msg){}

    ~newE(){
        std::cout<<"d newE"<<std::endl;
    }
};

void test(int a) throw(newE,myE){
    if(a > 0)
        throw newE("newE");

    if(a < 0)
        throw myE("myE");
    std::cout<<"end"<<std::endl;
}


int main(){
    try{
        test01(4);
        myE e("");
    }catch(const char* str){
        std::cout<<"catch "<<str<<std::endl;
    }

    try{
        test(4);
    }
    catch(newE &e){
        std::cout<<e.msg<<std::endl;
        e.msg = "in";
    }
    catch(myE &e){
        std::cout<<e.msg<<std::endl;
        e.msg = "finish";
    }catch(...){
        std::cout<<"..."<<std::endl;
    }
}