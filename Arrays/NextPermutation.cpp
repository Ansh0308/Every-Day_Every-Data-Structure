#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

void reverse_array(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n / 2; i++) {
        swap(nums[i], nums[n - 1 - i]);
    }
}

void nextPermutation(vector<int>& nums) {
    int piv = -1, n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            piv = i;
            break;
        }
    }

    if (piv == -1) {
        reverse_array(nums);
        return;
    }

    for (int i = n - 1; i > piv; i--) {
        if (nums[i] > nums[piv]) {
            swap(nums[piv], nums[i]);
            break;
        }
    }

    int i = piv + 1, j = n - 1;
    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

void val_array(vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }
}

void print_array(const vector<int> &nums) {
    for (int ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    cout << "Plz enter the n:" << endl;
    int n;
    cin >> n;
    vector<int> array(n);

    cout << "Plz enter the array:" << endl;
    val_array(array);

    nextPermutation(array);

    cout << "The nextPermutation array is:" << endl;
    print_array(array);

    return 0;
}
