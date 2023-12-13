#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#define FLOOP(i, a, b) for (int i = a; i < b; i++)
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int, 
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ixset;

int main() {
    int n, k;
    cin >> n >> k;
    ixset circle;

    FLOOP(i, 0, n) circle.insert(i + 1);
    int index = k;

    while (!circle.empty()){
        index = index % circle.size();
        auto t = circle.find_by_order(index);
        cout << *t << " ";
        circle.erase(t);
        index += k;
    }
}
