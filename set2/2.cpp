#include <iostream>
#include <vector>
#include <algorithm>
#define FLOOP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef vector<long> vlong;

int main() {
    int n;
    cin >> n;
    vlong coins(n, 0);

    long cns;
    FLOOP(i, 0, n) {
        cin >> cns;
        coins[i] = cns;
    }

    sort(coins.begin(), coins.end());

    long minsum = 0;
    bool found = false;
    for (long coin : coins) {
        if (coin > minsum + 1) {
            minsum += 1;
            found = true;
            break;
        }
        minsum += coin;
    }

    if (!found) {
        minsum += 1;
    }

    cout << minsum;
}
