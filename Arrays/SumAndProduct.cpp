#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(int array[],int n){
    
    
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    return;

}
int sum_of_array(int array[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    return sum;

}
int product_of_array(int array[],int n){
    int product=1;
    for(int i=0;i<n;i++){
        product*=array[i];
    }
    return product;

}
int main(){
    int n;
    cin>>n;
    int array[n];
    val_array(array,n);
    cout<<"Sum of the Array is "<<sum_of_array(array,n)<<endl;
    cout<<"Product of the Array is "<<product_of_array(array,n)<<endl;
    return 0;


}
