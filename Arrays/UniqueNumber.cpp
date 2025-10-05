#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> singleNum(vector<int>& arr) {
    //     // Code here.
    //      unordered_map<int, int> freqMap;
    
    // // Count frequency of each element
    // for (int num : arr) {
    //     freqMap[num]++;
    // }
    
    // vector<int> uniqueNumbers;
    // // Find elements with frequency 1
    // for (const auto& entry : freqMap) {
    //     if (entry.second == 1) {
    //         uniqueNumbers.push_back(entry.first);
    //     }
    // }
    
    // // Sort the two unique elements in increasing order
    // sort(uniqueNumbers.begin(), uniqueNumbers.end());
    // return uniqueNumbers;
    int xorval=0;
    for(int ele : arr){
        xorval^=ele;
    }
    int diffBit=xorval & (-xorval);
    int num1=0,num2=0;
    for(int ele : arr){
        if(ele & diffBit){
            num1^=ele;
        }
        else{
            num2^=ele;
        }
    }
    if(num1>num2){
        swap(num1,num2);
    }
    return {num1,num2};
    }
int main() {
    vector<int> arr = {2, 3, 7, 9, 2, 3, 7, 11};

    vector<int> result = singleNum(arr);

    cout << "The two unique numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}