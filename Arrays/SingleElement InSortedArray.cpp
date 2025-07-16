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
Finds the single non-duplicate element in a sorted array:
- Assumes every element appears twice except one unique element.
- Uses binary search for O(log n) time.
*/
int singleNonDuplicate(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];

    int st = 0, end = nums.size() - 1;
    while(st <= end){
        int mid = st + (end - st) / 2;

        if(mid == 0){
            if(nums[mid] != nums[mid + 1]) return nums[mid];
        }
        else if(mid == nums.size() - 1){
            if(nums[mid] != nums[mid - 1]) return nums[mid];
        }
        else{
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
        }

        if(mid % 2 == 0){ // even index
            if(nums[mid] == nums[mid + 1]){
                st = mid + 2;
            }
            else{
                end = mid - 1;
            }
        }
        else{ // odd index
            if(nums[mid] == nums[mid - 1]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;
}


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> array(n);

    cout << "Plz enter the array (could be  sorted array):" << endl;
    val_array(array);


    
        int result = singleNonDuplicate(array);
        if(result != -1){
            cout << "Single Non-Duplicate Element: " << result << endl;
        }
        else{
            cout << "No single non-duplicate element found." << endl;
        }
    
    

    return 0;
}
