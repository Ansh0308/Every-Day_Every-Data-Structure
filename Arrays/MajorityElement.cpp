// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
int MajorityEle(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    return(nums[n/2]);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    val_array(nums);
    cout<<"The Majority Element of the Array is "<<MajorityEle(nums)<<endl;
  
    
    return 0;


}
