#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
vector<int> PairSum(vector<int> &nums,int target){
    vector<int> ans(2,-1);
    int left=0,right=nums.size()-1;
    while(left<right){
        int sum=nums[left]+nums[right];
        if(sum==target){
            ans[0]=left;
            ans[1]=right;
            return ans;
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    val_array(nums);
   
    int target;
    cout<<"Enter the Target"<<endl;
    cin>>target;

    vector<int> ans=PairSum(nums,target);
    cout<<"The target found at "<<ans[0]<<" And "<<ans[1]<<endl;
    
  
    
    return 0;


}
