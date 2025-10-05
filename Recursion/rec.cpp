#include <bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n<2)return n;
    return fib(n-1)+fib(n-2);
}
void fib_(int n,int a=0,int b=1){
if(n==0){
    cout<<a;
    return;
}
cout<<a<<" ";
fib_(n-1,b,a+b);
}
int fib_memo(int n){
    if(n<=1)return n;
    vector<int> v(n);
    v[0]=0;
    v[1]=1;
    
    for(int i=2;i<n;i++){
        v[i]=v[i-1]+v[i-2];
    }
    return v[n-1];
}
int sum_vector(vector<int> v,int index=0){
    if(index==v.size()-1)return v[v.size()-1];
    return v[index]+sum_vector(v,index+1);
}
void any(int n,int temp=1){
    if(n==temp){
        cout<<temp;
        return;
    }
    cout<<temp<<" ";
    any(n,temp+1);
}
void any_(int n){
    if(n==1){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    any(n-1);
}
int factorial(int n){
    
    return (n<1)?1:n*factorial(n-1);
}
int main(){
    // cout<<fib(5);
    // any(10);
    cout<<fib_memo(43);
    // cout<<sum_vector({1,2,3,4,5});
    // cout<<factorial(5);
    
    return 0;
}//scope local,global,