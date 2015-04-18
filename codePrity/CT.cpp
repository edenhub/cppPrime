#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int cnt=0;
void dfs(int sum,int n,stack<int>& st,vector<int>& res){

    if(sum==0 && n==0){
        cnt++;
        vector<int>::iterator iter = res.begin();
        while(iter!=res.end()){
            cout<<*iter++<<" ";
        }
        cout<<endl;
        return;
    }

    if(sum>0){
        int t = st.top();
        res.push_back(t);
            st.pop();
        dfs(sum-1,n,st,res);
        res.pop_back();
        st.push(t);
    }


        // res.pop_back();

    if(n>0){
        st.push(n);
        dfs(sum+1,n-1,st,res);
        st.pop();
    }
}

int main(){
    int sum=0,n=7;
    vector<int> res;
    stack<int> st;
    dfs(sum,n,st,res);
    cout<<cnt<<endl;

    return 0;
}