#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
int BinarySearch(vector<int>& array,int target){
    int n=array.size();
    int start=0,end=n-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(array[mid]==target){
            return mid;
        }
        else if(array[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    
    return -1;


}
int BinarySearch_recursive(vector<int>& array,int target,int start,int end){
    
    int mid=start + (end-start)/2;
    if(end<start){
        return -1;
    }
    if(array[mid]==target){
        return mid;
    }
    else if(array[mid]>target){
        return BinarySearch_recursive(array,target,start,mid-1);
    }
    else{
        return BinarySearch_recursive(array,target,mid+1,end);
    }


}
int main(){
    int n;
    cin>>n;
    vector<int> array(n);
    cout<<"Plz enter the sorted array"<<endl;
    val_array(array);
    cout<<"enter the Target"<<endl;
    int target;
    cin>>target;
    
    cout<<"Target at "<<BinarySearch(array,target)<<endl;
    return 0;


}
