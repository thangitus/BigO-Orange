#include <bits/stdc++.h>

using namespace std;

typedef long long long2;
const int L = 1000001;
const long2 MAX1 = 1e9 + 7;
const long2 MAX2 = 1e9 + 9;
const long2 base = 257;

int n, m;
string s, t;
long2 f1[L], f2[L];
set<pair<long2, long2>> dic;

void init() {
    f1[0] = f2[0] = 1;
    for (int i = 1; i < L; i++) {
        f1[i] = (f1[i - 1] * base) % MAX1;
        f2[i] = (f2[i - 1] * base) % MAX2;
    }
}

long2 polyHash(const string &keys, long2 MOD) {
    long2 hashValue = 0;
    for (char key : keys)
        hashValue = (hashValue * base + key) % MOD;
    return hashValue;
}

bool check(const string &query) {
    long2 h1 = polyHash(query, MAX1);
    long2 h2 = polyHash(query, MAX2);

    long2 len = query.length();
    for (int i = 0; i < (int) query.size(); i++) {
        for (long2 c = 'a'; c <= 'c'; c++) {
            if (c == query[i]) continue;
            long2 newHashValue1 =
                    ((((c - query[i]) * f1[len - i - 1]) % MAX1 + MAX1) + h1) % MAX1;
            long2 newHashValue2 =
                    ((((c - query[i]) * f2[len - i - 1]) % MAX2 + MAX2) + h2) % MAX2;
            if (dic.count({newHashValue1, newHashValue2}))
                return true;
        }
    }
    return false;
}

int main() {
    init();
    cin >> n >> m;
    dic.clear();
    while (n--) {
        cin >> s;
        dic.insert({polyHash(s, MAX1), polyHash(s, MAX2)});
    }

    while (m--) {
        cin >> t;
        if (check(t))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}