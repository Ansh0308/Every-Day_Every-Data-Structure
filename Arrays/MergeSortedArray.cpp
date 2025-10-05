#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void val_array(vector<int> &array,int n){
    for(int i = 0; i < n; i++){
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
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else if(nums1[i]<nums2[j]){
                nums1[k--]=nums2[j--];
            }
            else{
                nums1[k--]=nums1[i--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
        
    }


int main() {
    cout << "Plz enter the m:" << endl;
    int m;
    cin >> m;
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> nums1(n+m, 0);
    vector<int> nums2(n);

    

    cout << "Plz enter the array: nums1 " << endl;
    val_array(nums1,m);
    cout << "Plz enter the array: nums2 " << endl;
    val_array(nums2,n);
    
    cout<<"The Merge Sorted array  is "<<endl;
    merge(nums1,m,nums2,n);
    
    print_array(nums1);



    return 0;
}
