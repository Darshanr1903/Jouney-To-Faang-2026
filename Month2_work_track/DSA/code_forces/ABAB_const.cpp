#include<iostream>
using namespace std;
bool f(string& T,string& X,int i,int j,int idx){
    if(idx>=(int)T.length()) return true;
    if(i>j) return false;
    if(X[idx]=='?'||(X[idx]==T[i]&&X[idx]==T[j])){
        return f(T,X,i+1,j,idx+1)||f(T,X,i,j-1,idx+1);
    }
    if(X[idx]==T[i]||X[idx]==T[j]){
        if(X[idx]==T[i]) return f(T,X,i+1,j,idx+1);
        else return f(T,X,i,j-1,idx+1);
    }
    else return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string X;
        cin>>X;
        string T;
        for(int i=0;i<n;i++){
            if(i%2==0) T+='a';
            else T+='b';
        }
        if(f(T,X,0,n-1,0)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
