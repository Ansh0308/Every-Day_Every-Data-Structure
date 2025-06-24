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
void SwapSmallestLargest(int array[],int n){
    int smallest=0,largest=0;
    for(int i=0;i<n;i++){
        if(array[i]<array[smallest]){
            smallest=i;
        }
        if(array[i]>array[largest]){
            largest=i;
        }
    }
    int temp=array[smallest];
    array[smallest]=array[largest];
    array[largest]=temp;
    
    return;
    
}
int main(){
    int n;
    cin>>n;
    int array[n];
    val_array(array,n);
    cout<<"Before Swap "<<endl;
    PrintArray(array,n);
    SwapSmallestLargest(array,n);
    cout<<"After Swap "<<endl;
    PrintArray(array,n);
    return 0;


}
