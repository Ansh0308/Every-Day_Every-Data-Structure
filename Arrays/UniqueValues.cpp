#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void val_array(int array[],int n){
    
    
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    return;

}
void UniqueValues(int arr[],int n){
    set<int> uniqueValues;
    for(int i=0;i<n;i++){
        (uniqueValues.find(arr[i]) != uniqueValues.end())
            ? (void)uniqueValues.erase(arr[i])
            : (void)uniqueValues.insert(arr[i]);

    }
    cout << "Unique values in the array: ";
    for (const int& value : uniqueValues) {
        cout << value << " ";
    }
    cout << endl;
    return;
}

int main(){
    int n;
    cin>>n;
    int array[n];
    val_array(array,n);
    UniqueValues(array,n);
  
    
    return 0;


}
