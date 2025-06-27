#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(int array[],int n){
    
    
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    return;

}
int LinearSearch(int array[],int n,int target){
    for(int i=0;i<n;i++){
        if(array[i]==target){
            return i;
        }
    }
    return -1;


}
int main(){
    int n;
    cin>>n;
    int array[n];
    val_array(array,n);
    cout<<"enter the Target"<<endl;
    int target;
    cin>>target;
    cout<<"Target at "<<LinearSearch(array,n,target)<<endl;
    return 0;


}
