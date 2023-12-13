#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FLOOP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef pair<int, int> pi;
typedef vector <pi> vpi;

int main() {
    int n;
    cin >> n;
    vpi m;

    FLOOP(i, 0, n) {
        int a;
        int b;
        cin >> a >> b;
        m.PB(MP(b, a));
    }

    sort(m.begin(), m.end());
    
    int m1 = m[0].F;
    int lkm = 1;

    FLOOP(i, 1, n) {
        if (m[i].S >= m1) {
            lkm++;
            m1 = m[i].F;
        }
    }

    cout << lkm;
}
