#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(int array[],int n){
    
    
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    return;

}
void PrintArray(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<endl;
    }
    return;
}
void ReverseArray(int array[],int n){
    for(int i=0;i<n/2;i++){
        array[n-i-1]=array[i]*array[n-i-1];
        array[i]=array[n-i-1]/array[i];
        array[n-i-1]=array[n-i-1]/array[i];

    }
    return;
}
int main(){
    int n;
    cin>>n;
    int array[n];
    val_array(array,n);
    ReverseArray(array,n);
    PrintArray(array,n);
    
    return 0;


}
