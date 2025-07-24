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
void InsertionSort(vector<int> &nums){
    int n=nums.size();
    for(int i=1;i<n;i++){
        int current=nums[i],temp=i;
        
        for(int prev=i-1;prev>=0 && nums[prev]> current;prev--){
            if(nums[prev]>current){
                nums[prev+1]=nums[prev];
                temp=prev;

            }
        }
        nums[temp]=current;
    }
}


int main() {
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> array(n);
    

    cout << "Plz enter the array:" << endl;
    val_array(array);
    InsertionSort(array);
    cout<<"The Sorted array  is "<<endl;
    
    print_array(array);



    return 0;
}
