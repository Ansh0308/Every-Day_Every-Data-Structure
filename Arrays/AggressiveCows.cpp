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
    int cows=1,lastPo=arr[0];
    for(int i=1;i<arr.size();i++){
        
        if(arr[i]-lastPo>=mid){
            cows++;
            lastPo=arr[i];
            if(cows>m)return false;

        }
    }
    
    return (cows!=m)?false:true;

}
int LargestMinDistance(vector<int> &arr,int n,int m){
    
    int st=1,end=1;
    sort(arr.begin(),arr.end());
    end=arr[arr.size()-1]-arr[0];
    int ans=-1;
    
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr,n,m,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    
    return ans;
}


int main() {
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> array(n);
    cout << "Plz enter the cows:" << endl;
    int m;
    cin >> m;

    cout << "Plz enter the array:" << endl;
    val_array(array);
    cout<<"The Largest Min distance between cows is "<<LargestMinDistance(array,n,m)<<endl;



    return 0;
}
