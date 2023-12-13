#include <iostream>
#include <vector>

using namespace std;

void settiprintteri(vector<long> i) {
    cout << i.size() << "\n";
    for (long nro : i) {
        cout << nro << " ";
    }
    cout << "\n";
}

int main() {
    long n;
    cin >> n;

    long sum = n * (n + 1) / 2;

    if (sum % 2 == 0) {
        cout << "YES" << "\n";
        vector<long> s1, s2;
        long half = sum/2;

        for (long i = n; i >= 1; i--) {
            if (i <= half) {
                s1.push_back(i);
                half -= i;
            } else {
                s2.push_back(i);
            }
        }

        settiprintteri(s1);
        settiprintteri(s2);
    } else {
        cout << "NO";
    }
}
