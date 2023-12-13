#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums[x-1] = i;
    }

    int mvs = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            mvs++;
        }
    }

    cout << mvs;
}
