#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void val_array(vector<int> &array){
    for(int i = 0; i < array.size(); i++){
        cin >> array[i];
    }
    return;
}
bool isValid(vector<int> &arr,int n,int m,int mid){
    int painters=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            return false;
        }
        if(sum+arr[i]>mid){
            painters++; 
            sum=arr[i];
            if(painters>m){
                return false;
            }
        }
        else{
            sum+=arr[i];
        }
    }
    return true;

}
int PaintersAllocation(vector<int> &arr,int n,int m){
    
    int st=*max_element(arr.begin(), arr.end()),end=accumulate(arr.begin(),arr.end(), 0);
    int ans=INT_MAX;
    
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr,n,m,mid)){
            ans=min(ans,mid);
            end=mid-1;
        }
        else{
            st=mid+1;
        }

    }
    
    return ans;
}


int main() {
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> array(n);
    cout << "Plz enter the m:" << endl;
    int m;
    cin >> m;

    cout << "Plz enter the array:" << endl;
    val_array(array);
    cout<<"The Min time req by the painters is "<<PaintersAllocation(array,n,m)<<endl;



    return 0;
}
