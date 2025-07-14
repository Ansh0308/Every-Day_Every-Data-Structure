#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(vector<int> &array){
    
    
    for(int i=0;i<array.size();i++){
        cin>>array[i];
    }
    return;

}
int RotatedSortedArraySearch(vector<int>& array, int target) {
    int start = 0, end = array.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (array[mid] == target) {
            return mid;
        }

        // Check which half is sorted
        if (array[start] <= array[mid]) {  // Left half sorted
            if (array[start] <= target && target < array[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {  // Right half sorted
            if (array[mid] < target && target <= array[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int BinarySearch(vector<int>& array,int target){
    int n=array.size();
    int start=0,end=n-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(array[mid]==target){
            return mid;
        }
        else if(array[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    
    return -1;


}
int BinarySearch_recursive(vector<int>& array,int target,int start,int end){
    
    int mid=start + (end-start)/2;
    if(end<start){
        return -1;
    }
    if(array[mid]==target){
        return mid;
    }
    else if(array[mid]>target){
        return BinarySearch_recursive(array,target,start,mid-1);
    }
    else{
        return BinarySearch_recursive(array,target,mid+1,end);
    }


}
int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    cout << "Plz enter the array (can be rotated sorted array):" << endl;
    val_array(array);
    cout << "Enter the Target:" << endl;
    int target;
    cin >> target;

    cout << "Binary Search (Normal Sorted Array): " << BinarySearch(array, target) << endl;
    cout << "Binary Search (Rotated Sorted Array): " << RotatedSortedArraySearch(array, target) << endl;

    return 0;
}

