#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
int maxArea(vector<int> &nums){
    int n=nums.size(),left=0,right=n-1,MaxArea=0;
    while(left!=right && left<n && right>=0){
        int width=right-left;
        int currentArea=min(nums[left],nums[right])*width;
        MaxArea=max(MaxArea,currentArea);
        (nums[left]<nums[right])?(left++):(right--);
    }
    return MaxArea;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    val_array(nums);
    cout<<"The maximum amount of water a container can store is "<<maxArea(nums)<<endl;
  
    
    return 0;


}
