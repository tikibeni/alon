#include <iostream>
#include <set>
#define FLOOP(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef multiset <int> mset;

int main() {
    int n, m;
    cin >> n >> m;
    mset prices;
    FLOOP(i, 0, n) {
        int p;
        cin >> p;
        prices.insert(-p);
    }
    FLOOP(i, 0, m) {
        int max;
        cin >> max;
        auto price = prices.lower_bound(-(max));
        if (price != prices.end()) {
            cout << -(*price) << "\n";
            prices.erase(prices.find(*price));
        } else {
            cout << -1 << "\n";
        }
    }

}
