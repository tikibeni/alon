#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FLOOP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back
#define MP make_pair
using namespace std;

typedef vector<int> vint;
typedef priority_queue<pair<int, int>> pairprqu;

int main() {
    int n;
    cin >> n;
    pairprqu rooms;
    vector<vint> customers;

    FLOOP(i, 0, n) {
        vint custInfo;
        int a, b;
        cin >> a >> b;
        custInfo.PB(a);
        custInfo.PB(b);
        custInfo.PB(i);
        customers.PB(custInfo);
    }

    sort(customers.begin(), customers.end());

    int roomsReq = 0;
    int nums[n];

    FLOOP(i, 0, n) {
        if (rooms.empty()) {
            roomsReq = 1;
            rooms.push(MP(-customers[i][1], roomsReq));
            nums[customers[i][2]] = roomsReq;
        } else if (rooms.top().first <= -customers[i][0]) {
            roomsReq++;
            rooms.push(MP(-customers[i][1], roomsReq));
            nums[customers[i][2]] = roomsReq;
        } else {
            int rn = rooms.top().second;
            rooms.pop();
            rooms.push(MP(-customers[i][1], rn));
            nums[customers[i][2]] = rn;
        }
    }

    cout << roomsReq << "\n";
    FLOOP(i, 0, n) cout << nums[i] << " ";
}
