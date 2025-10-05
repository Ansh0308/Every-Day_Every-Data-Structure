#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(int array[],int n){
    
    
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    return;

}
void SmallestLargestIndex(int array[],int n){
    int smallest=0,largest=0;
    for(int i=0;i<n;i++){
        if(array[i]<array[smallest]){
            smallest=i;
        }
        if(array[i]>array[largest]){
            largest=i;
        }
    }
    cout<<"Smallest number index  is "<<smallest<<endl;
    cout<<"Largest number index is "<<largest<<endl;
    return;
    
}
int main(){
    int n;
    cin>>n;
    int array[n];
    val_array(array,n);
    SmallestLargestIndex(array,n);
    return 0;


}
