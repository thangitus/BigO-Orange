#include <bits/stdc++.h>


using namespace std;
struct Stone {
    int pos;
    bool isBig;
};

int main() {
    int t, n, d;
    char c;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n >> d;
        vector<Stone> stones(n + 1);
        int pos[]{0, 0}, result = 0;
        stones.back() = {d, true};
        for (int i = 0; i < n; i++) {
            cin >> c;
            stones[i].isBig = c == 'B';
            cin >> c;
            cin >> stones[i].pos;
        }
        for (auto &stone:stones) {
            if (stone.isBig) {
                result = max({result, stone.pos - pos[0], stone.pos - pos[1]});
                pos[0] = pos[1] = stone.pos;
            } else {
                int minPos = pos[0] < pos[1] ? 0 : 1;
                result = max(result, stone.pos - pos[minPos]);
                pos[minPos] = stone.pos;
            }
        }
        cout << "Case " << k << ": " << result << endl;
    }
}