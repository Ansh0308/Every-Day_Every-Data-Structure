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
void DNF(vector<int> &nums){
    int n=nums.size();
    int low =0,mid=0,high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
            

        }
        else{
            mid++;
        }
    }
    
}


int main() {
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> array(n);
    

    cout << "Plz enter the array:(Have 3 elements only)" << endl;
    val_array(array);
    DNF(array);
    cout<<"The Sorted array  is "<<endl;
    
    print_array(array);



    return 0;
}
