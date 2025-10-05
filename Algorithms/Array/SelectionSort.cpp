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
void SelectionSort(vector<int> &nums){
    int n=nums.size();
    int min_ele=nums[0];
    for(int i=0;i<n;i++){
        int min_ele=i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[min_ele]){
                min_ele=j;
            }
            }
            swap(nums[i],nums[min_ele]);
    }
}


int main() {
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> array(n);
    

    cout << "Plz enter the array:" << endl;
    val_array(array);
    SelectionSort(array);
    cout<<"The Sorted array  is "<<endl;
    
    print_array(array);



    return 0;
}
