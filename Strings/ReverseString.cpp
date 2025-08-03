#include<iostream>
#include<vector>
#include<string>
using namespace std;

void PrintString(vector<char>& array) {
    for(char ele : array) {
        cout << ele;
    }
    cout << endl;
}

void ReverseString(vector<char>& array) {
    int n = array.size();
    for(int i = 0; i < n / 2; ++i) {
        swap(array[i], array[n - 1 - i]);
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> array(n);
    for(int i = 0; i < n; ++i) {
        array[i] = s[i];
    }

    ReverseString(array);
    PrintString(array);

    return 0;
}
