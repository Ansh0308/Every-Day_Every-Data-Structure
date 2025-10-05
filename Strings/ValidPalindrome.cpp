#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if string is a palindrome (alphanumeric & case-insensitive)
bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;
        if (tolower(s[i]) != tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}

void PrintString(vector<char>& array) {
    for (char ele : array) {
        cout << ele;
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    

    // Check palindrome
    if (isPalindrome(s)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    

    return 0;
}
