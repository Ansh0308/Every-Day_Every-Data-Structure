#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(int array[],int n){
    
    
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    return;

}
void SmallestLargest(int array[],int n){
    int smallest=INT_MAX,largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(array[i]<smallest){
            smallest=array[i];
        }
        if(array[i]>largest){
            largest=array[i];
        }
    }
    cout<<"Smallest number is "<<smallest<<endl;
    cout<<"Largest number is "<<largest<<endl;
    return;
    
}
int main(){
    int n;
    cin>>n;
    int array[n];
    val_array(array,n);
    SmallestLargest(array,n);
    return 0;


}
