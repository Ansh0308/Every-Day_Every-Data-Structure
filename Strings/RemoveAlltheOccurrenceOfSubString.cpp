#include<iostream>
#include<vector>
#include<string>
using namespace std;

// The removeOccurrences function as a standalone function
string removeOccurrences(string s, string part) {
    int flag = 1;
    while(flag){
        int index = s.find(part);
        if(index < s.length()){
            s.erase(index, part.length());
        }
        else{
            flag = 0;
        }
    }
    return s;
}

// Function to print a vector of chars as a string
void PrintString(vector<char>& array) {
    for(char ele : array) {
        cout << ele;
    }
    cout << endl;
}



int main() {
    int n;
    cin >> n;
    cout<<"Enter the string "<<endl;

    string s;
    cin >> s;
    cout<<"Enter the part "<<endl;

    // Ask for the 'part' substring to remove
    string part;
    cin >> part;

    // Remove all occurrences of 'part' from input string
    s = removeOccurrences(s, part);
    cout<<"After removing : "<<s<<endl;

    return 0;
}
