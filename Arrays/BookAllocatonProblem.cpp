#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void val_array(vector<int> &array){
    for(int i = 0; i < array.size(); i++){
        cin >> array[i];
    }
    return;
}
bool isValid(vector<int> &books,int n,int m,int mid){
    int student=1,sum=0;
    for(int i=0;i<n;i++){
        if(books[i]>mid){
            return false;
        }
        if(sum+books[i]>mid){
            student++; 
            sum=books[i];
            if(student>m){
                return false;
            }
        }
        else{
            sum+=books[i];
        }
    }
    return true;

}
int BookAllocation(vector<int> &books,int n,int m){
    if(m>n)return -1;
    int st=0,end=accumulate(books.begin(),books.end(), 0);
    int ans=INT_MAX;
    
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(books,n,m,mid)){
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
    cout<<"The Min number of the pages is "<<BookAllocation(array,n,m)<<endl;



    return 0;
}
