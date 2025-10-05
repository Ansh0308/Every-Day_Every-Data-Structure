#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
int KadanesAlgo(vector<int> &nums){
    int currentSum=0,maxSum=INT_MIN;
    for(int ele : nums){
        currentSum=max(ele,currentSum + ele);
        maxSum=max(maxSum,currentSum);
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    val_array(nums);
    cout<<"The Maximum Sum Of the subarray is "<<KadanesAlgo(nums)<<endl;
  
    
    return 0;


}
