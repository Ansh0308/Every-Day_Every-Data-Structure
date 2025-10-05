#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
void PrintArray(vector<int> &array){
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return;
}
vector<int> productExceptSelf(vector<int> &nums){
    int n=nums.size();
    vector<int> ans(n,1);
    int product_pre_suf=1;
    for(int i=1;i<n;i++){
        product_pre_suf*=nums[i-1];
        ans[i]=product_pre_suf;
    }
    product_pre_suf=1;
    for(int i=n-1;i>=0;i--){
        ans[i]*=product_pre_suf;
        product_pre_suf*=nums[i];
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    val_array(nums);
    vector<int> ans=productExceptSelf(nums);
    cout<<"The  Product of Array Except Self  is ";
    PrintArray(ans);
  
    
    return 0;


}
