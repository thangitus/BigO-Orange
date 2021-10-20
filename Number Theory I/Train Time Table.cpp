#include <bits/stdc++.h>


using namespace std;

void readTrip(vector<pair<int, int>> &trips, int delay) {
    int h, m;
    char c;
    for (auto &trip : trips) {
        cin >> h >> c >> m;
        trip.first = h * 60 + m;
        cin >> h >> c >> m;
        trip.second = h * 60 + m + delay;
    }
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int delay, n[2], result[2];
        cin >> delay >> n[0] >> n[1];
        vector<pair<int, int>> trip[2];
        trip[0].resize(n[0]), trip[1].resize(n[1]);
        readTrip(trip[0], delay);
        readTrip(trip[1], delay);
        result[0] = n[0], result[1] = n[1];
        for (int j = 0; j < 2; ++j) {
            int waiting = j, travelling = (j + 1) % 2;
            sort(trip[waiting].begin(), trip[waiting].end());
            sort(trip[travelling].begin(), trip[travelling].end(), compare);
            int i1 = 0, i2 = 0;
            while (i1 < n[waiting] && i2 < n[travelling]) {
                if (trip[waiting][i1].first >= trip[travelling][i2].second) {
                    result[waiting]--;
                    i2++;
                }
                i1++;
            }
        }
        cout << "Case #" << k << ": " << result[0] << " " << result[1] << endl;
    }
}
