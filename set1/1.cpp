#include <iostream>

using namespace std;

int main() {
    long n;
    cin >> n;

    while (n > 1) {
        std::cout << n << " ";
        if (n % 2 == 0) {
            n = n / 2;
            continue;
        } else {
            n = n * 3 + 1;
        }
    }
    std::cout << n;
}
