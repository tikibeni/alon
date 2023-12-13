#include <iostream>
#include <vector>
#include <map>
#define FLOOP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back
using namespace std;

typedef vector<int> vint;
typedef map<int, int> mint;

int main() {
    int n, k;
    cin >> n >> k;
    vint nums;
    
    FLOOP(i, 0, n) {
        int x;
        cin >> x;
        nums.PB(x);
    }

    long subs = 0;
    int distincts = 1;
    int innerIndex = 0;
    mint chklst;
    
    chklst[nums[0]] = 1;

    FLOOP(i, 0, n) {
        if (i != 0) {
            int prevNumber = nums[i - 1];
            chklst[prevNumber]--;
            if (chklst[prevNumber] == 0) distincts--;
        }
        
        while (
            (innerIndex < (n - 1) && distincts < k) || 
            (innerIndex < (n - 1) && chklst[nums[innerIndex + 1]] >= 1)
        ) {
            innerIndex++;
            int number = nums[innerIndex];
            if (chklst.count(number)) {
                if (chklst[number] == 0) distincts++;
                chklst[number]++;
            } else {
                chklst[number] = 1;
                distincts++;
            }

            subs += innerIndex - i;
        }

        subs++;
    }

    cout << subs;
}
