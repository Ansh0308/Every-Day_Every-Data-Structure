#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b) {
    if(a==0)return b;
    if(b==0)return a;
    if(a>b){
        return GCD(a%b,b);
    }
    else{
        return GCD(a,b%a);
    }
}

int main() {
    int a;
    cout << "Enter a number a: ";
    cin >> a;
    int b;
    cout << "Enter a number b: ";
    cin >> b;

    
    cout << "GCD of these are " << GCD(a,b) << endl;

    return 0;
}
