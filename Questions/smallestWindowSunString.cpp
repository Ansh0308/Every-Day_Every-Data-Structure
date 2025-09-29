#include <bits/stdc++.h>
using namespace std;

// Function declaration
string smallestWindow(string s, string p);



// Function definition (to be implemented)
bool isValid(string &sub, string &p, int mid, int &start) {
    unordered_map<char,int> freq_map;
    for (char c : p) freq_map[c]++;
    unordered_map<char,int> window;
    int formed = 0;
    for (int i = 0; i < (int)sub.size(); i++) {
        char c = sub[i];

        if (i >= mid && freq_map.count(sub[i - mid])) {
            char out_char = sub[i - mid];
            window[out_char]--;
            if (window[out_char] < freq_map[out_char]) {
                formed--;
            }
        }
        if (freq_map.count(c)) {
            window[c]++;
            if (window[c] == freq_map[c]) {
                formed++;
            }
        }
        if (i >= mid - 1 && formed == (int)freq_map.size()) {
            start = i - mid + 1;
            return true;
        }
    }
    return false;
}



string smallestWindow(string s, string p) {
    int s_n = s.length(), p_n = p.length();
    if (p_n > s_n) return "-1";

    int low = p_n, high = s_n;
    int min_len = INT_MAX, start_index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int start_i = -1;
        if (isValid(s, p, mid, start_i)) {
            if (mid < min_len) {
                min_len = mid;
                start_index = start_i;
            }
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (start_index == -1) return "-1";
    return s.substr(start_index, min_len);
}

int main() {
    string s, p;
    cout<<"Enter S"<<endl;
    cin >> s;
    
    cout<<"Enter p"<<endl;
    cin>> p;
    cout << smallestWindow(s, p) << endl;
    return 0;
}