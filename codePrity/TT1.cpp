#include <iostream>
#include <string.h>

using namespace std;

const int N=1000;
bool isPara(char* str,int len){
    int s = 0,e = len-1;
    while(s<=e){
        if(str[s++]!=str[e--])
            return false;
    }

    return true;
}

int cnt(char* str,int len){
    char tmp[N]={'\0'};

    for(int i=0;i<len;i++){
        for(int j=0 ;j<i+1;j++){
            tmp[j] = str[i+j];
        }
    }
}

int main(){
    char str1[] = {'a','b','a'};
    int len = sizeof(str1)/sizeof(char);
    cout<<isPara(str1,len);

    return 0;
}