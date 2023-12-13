#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<string> variaatiot;

void perms(string a, string b) {
    if (b == "") {
        variaatiot.insert(a);
        return;
    } else {
        for (int i = 0; i < b.length(); i++) {
            string x = a + b[i];
            string y = b.substr(0, i) + b.substr(i+1);
            perms(x, y);
        }
    }
}

int main() {
    string k;
    cin >> k;

    sort(k.begin(), k.end());
    perms("", k);
    cout << variaatiot.size() << "\n";

    for (string v : variaatiot) {
        cout << v << "\n";
    }
}
