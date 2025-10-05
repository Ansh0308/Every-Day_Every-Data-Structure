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
int MaxProfit(vector<int> &nums){
    int n=nums.size();
    int minPrice=nums[0],maxProfit=0;
    for(int ele : nums){
        minPrice=min(minPrice,ele);
        maxProfit=max(maxProfit,ele-minPrice);
    }
    return maxProfit;

}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    val_array(nums);
    cout<<"The Maximum Profit During Buying and Selling is "<<MaxProfit(nums)<<endl;
  
    
    return 0;


}
