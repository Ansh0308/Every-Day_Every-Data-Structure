#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
double Pown(double x,int n){
    long biform=n;
    double ans=1;
    if(n<0){
        biform*=-1;
        x=1/x;

    }
    while(biform>0){
        if(biform%2==1){
            ans*=x;
        }
        x*=x;
        biform/=2;
    }
    return ans;
}

int main(){
    double x;
    cout<<"Enter the Value of X"<<endl;
    cin>>x;
    cout<<"Enter the Value of n"<<endl;
    int n;
    cin>>n;
   
    cout<<"The "<<x<<" to the Power "<<n<<" is "<<Pown(x,n)<<endl;
  
    
    return 0;


}
