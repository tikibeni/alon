#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n;
    cin >> n;
    vector<long> numbers;
    numbers.reserve(n);

    for (int i = 0; i < n; i++) {
        long num;
        cin >> num;

        numbers.push_back(num);
    }

    long mvs = 0;
    for (int i = 1; i < n; i++) {
        if (numbers[i] <= numbers[i - 1]) {
            mvs += numbers[i-1] - numbers[i];
            numbers[i] = numbers[i-1];
        }
    }

    std::cout << mvs;
}
