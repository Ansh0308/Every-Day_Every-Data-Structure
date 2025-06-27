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
int MooresVote(vector<int> &nums){
    int n=nums.size();
    int freq=0,ans=nums[0];
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=nums[i];
        }
        (ans==nums[i])?freq++:freq--;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    val_array(nums);
    cout<<"The Majority Element of the Array is "<<MooresVote(nums)<<endl;
  
    
    return 0;


}
