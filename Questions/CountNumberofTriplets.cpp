// C++ program to count triplets with given
// product m
#include <bits/stdc++.h>
using namespace std;

// Function to count such triplets
int countTriplets(vector<int>& arr,  int m)
{
    int n=arr.size();
unordered_map<int,int> single;
for(int i=0;i<n;i++){
single[arr[i]]=i;
}
int count=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int check=arr[i]*arr[j];
        if(check!=0&&m%check==0){
            int third=m/check;
            auto it=single.find(third);
            if(it!=single.end() && it->second>i && it->second>j && it->first!=arr[i] && it->first!=arr[j]){
                count++;

            }
        }
    }
}
return count;

    
}

// Drivers code
int main()
{
    vector<int> arr= { 1, 4, 6, 2, 3, 8 };
    
    int m = 24;

    cout << countTriplets(arr, m);

    return 0;
}