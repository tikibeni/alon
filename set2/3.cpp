#include <iostream>
#include <vector>
#define PB push_back
#define FLOOP(i, a, b) for (int i = a; i < b; i++)
using namespace std;

typedef vector <int> vint;

int main() {
    int n;
    cin >> n;
    vint k, j;
    FLOOP(i, 0, n) k.PB(i + 1);
    int other = 1;
    while (k.size() > 1) {
        int sz = k.size();
        FLOOP(i, 0, sz) {
            if (i % 2 == other) {
                cout << k[i] << " ";
                if (i == sz - 1) other = 1;
            } else {
                j.PB(k[i]);
                if (i == sz - 1) other = 0;
            }
        }
        k = j;
        j.clear();
    }
    cout << k[0];
}
