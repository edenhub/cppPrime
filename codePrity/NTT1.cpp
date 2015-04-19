#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

map<string,int> mths;
// {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"}
void init(){
    mths["January"]=1;
    mths["February"]=2;
    mths["March"]=3;
    mths["April"]=4;
    mths["May"]=5;
    mths["June"]=6;
    mths["July"]=7;
    mths["August"]=8;
    mths["September"]=9;
    mths["October"]=10;
    mths["November"]=11;
    mths["December"]=12;
}

class Date{
public:
    int year,month,day;
    Date(int _year,int _month,int _day):year(_year),month(_month),day(_day){}
    Date(int _year,string _month,int _day):year(_year),month(mths[_month]),day(_day){}
};

ostream& operator<<(ostream& os,Date& date){
    os<<date.year<<" "<<date.month<<" "<<date.day<<endl;
}

bool isLeap(Date& src){
    if( (src.year %4 == 0 && src.year % 100 != 0) || (src.year % 400 == 0) ) return true;
    else return false;
}

int isLeap2(Date& src){
    if(src.year %4 == 0 && src.year % 100 != 0) return 1;
    else if(src.year % 400 == 0) return 2;
    else 0;
}


int cmp(Date& fir,Date& sec){
    int yearS = fir.year - sec.year;
    int monthS = fir.month - sec.month;
    int dayS = fir.day - sec.day;

    if(yearS == 0 && monthS==0 && dayS==0) return 0;

    if(yearS == 0 && monthS==0 && dayS > 0) return 1;
    else if(yearS == 0 && monthS==0 && dayS < 0) return -1;

    if(yearS == 0 && monthS >0 ) return 1;
    else if(yearS == 0 && monthS <0 ) return -1;

    if(yearS > 0) return 1;
    else if(yearS < 0) return -1;
}


Date nextLeap(Date& date){
    // int isL = isLeap(date);
    bool isL = isLeap(date);
    int year = date.year;
    Date tmp(year,2,29);
    if(!isL){
        year = (year - year % 4) + 4;
        tmp.year = year;
        // return tmp;
    }else{
        // if(cmp(date,tmp) <0) return tmp;
        // else{
        if(cmp(date,tmp)>=0){
            year += 4;
            tmp.year = year;}
            // return tmp;
        // }
    }

    // cout<<tmp<<endl;
    if(isLeap(tmp)) return tmp;
    else return nextLeap(tmp);
}

Date preLeap(Date& date){
    // int isL = isLeap(date);
    bool isL = isLeap(date);
    int year = date.year;
    Date tmp(year,2,29);
    if(!isL){
        year = year - year % 4;
        tmp.year = year;
        return tmp;
    }else{
        // if(cmp(date,tmp)>0) return tmp;
        // else{
        if(cmp(date,tmp)<=0){
            year -= 4;
            tmp.year = year;}

            // return tmp;
        // }
    }

// cout<<tmp<<endl;
    if(isLeap(tmp)) return tmp;
    else return preLeap(tmp);
}

int cnt(Date& beg,Date& end){
    Date front = nextLeap(beg),tail = preLeap(end);
    int cnt=0;

    while(cmp(front,tail)<=0){
        cnt++;
        front = nextLeap(front);
    }

    if(isLeap(beg) ){
        Date tmp = Date(beg.year,2,29);
        if(cmp(tmp,beg) == 0) cnt++;
    }


    if(isLeap(end) ){
        Date tmp = Date(end.year,2,29);
        if(cmp(tmp,end) == 0) cnt++;
    }



    return cnt;

}

int main(){
    init();
    int T;
    // Date d1(2899,8,12),d2(2901,8,12);
    // int ct = cnt(d1,d2);
    // cout<<ct<<endl;
    cin>>T;
    for(int i=1;i<=T;i++){
        string month,dot;
        int day;int year;
        cin>>month>>day>>dot>>year;
        Date beg(year,month,day);

        string month2;
        int day2;int year2;
        cin>>month2>>day2>>dot>>year2;
        Date end(year2,month2,day2);

        cout<<"Case #"<<i<<": "<<cnt(beg,end)<<endl;
    }

    return 0;
}