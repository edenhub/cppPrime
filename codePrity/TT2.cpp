#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

static int num=0;

inline bool juge(vector<char>& res){
    int s=0,e = res.size()-1;

    while(s<=e){
        if(res[s++] != res[e--]) return false;
    }
    return true;
}

inline void combine(char* src,int n,vector<char>& res){
    if(n==0){
        // num++;
        if(juge(res)) num++;
        return;
    }

    if(*src == '\0') return;
    res.push_back(*src);
    combine(src+1,n-1,res);
    res.pop_back();
    combine(src+1,n,res);
}

int main(){
    int T;
    cin>>T;
    const int MAX=1001;

    for(int j=1;j<=T;j++){
        char src[MAX];
        cin>>src;   
        int size = sizeof(src)/sizeof(char);
        for(int i=1;i<=size;i++){
        vector<char> v(MAX);
        combine(src,i,v);
    }
    printf("Case #%d: %d\n",j,num%100007);
        // cout<<"Case #"<<j<<": "<<(num%100007)<<endl;
        num=0;
    }

    return 0;
}