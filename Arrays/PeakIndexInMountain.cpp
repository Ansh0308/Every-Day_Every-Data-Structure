#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void val_array(vector<int> &array){
    for(int i = 0; i < array.size(); i++){
        cin >> array[i];
    }
    return;
}

/*
Note:
The function below assumes that the input array is a proper mountain array:
- A mountain array is an array where elements strictly increase to a single peak element,
  and then strictly decrease.
- If the array doesn't satisfy this condition, the function will return -1.
*/
int peakIndexInMountainArray(vector<int>& arr) {
    int st = 1, end = arr.size() - 2;
    while(st <= end){
        int mid = st + (end - st) / 2;
        if(arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
            return mid;  // Peak found
        if(arr[mid] > arr[mid - 1]){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;  // No peak found (not a mountain array)
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);

    cout << "Plz enter the array (can be or mountain array):" << endl;
    val_array(array);

    

    // For Mountain Array Peak Index
    int peakIndex = peakIndexInMountainArray(array);
    if (peakIndex != -1) {
        cout << "Peak Index in Mountain Array: " << peakIndex << endl;
        cout << "Peak Element: " << array[peakIndex] << endl;
    } else {
        cout << "Peak not found (array might not be a proper mountain array)." << endl;
    }

    return 0;
}
