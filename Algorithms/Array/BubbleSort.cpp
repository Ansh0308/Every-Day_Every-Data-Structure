#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void val_array(vector<int> &array){
    for(int i = 0; i < array.size(); i++){
        cin >> array[i];
    }
    return;
}
void print_array(vector<int> &nums){
    for(int ele : nums){
        cout<<ele<<" ";
    }
    cout<<endl;
}
void BubbleSort(vector<int> &nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                flag=1;
            }
        }
        if(flag==0)return;
    }
    return ;
}


int main() {
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> array(n);
    

    cout << "Plz enter the array:" << endl;
    val_array(array);
    BubbleSort(array);
    cout<<"The Sorted array  is "<<endl;
    
    print_array(array);



    return 0;
}
