#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int nums[5];
pair<ll, ll> minVal{10000, 1};
vector<int> result;
bool visited[5]{false};

pair<ll, ll> subtract(ll &a, ll &b, ll &c, ll &d) {
    pair<ll, ll> ans;
    ans.first = abs(a * d - c * b);
    ans.second = b * d;
    ll gcd = __gcd(ans.first, ans.second);
    ans.first /= gcd;
    ans.second /= gcd;
    return ans;
}

bool isSmall(pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.first * b.second < b.first * a.second;
}

void permutation(vector<int> &cur) {
    if (cur.size() == 4) {
        ll a = nums[cur[0]], b = nums[cur[1]], c = nums[cur[2]], d = nums[cur[3]];
        auto value = subtract(a, b, c, d);
        if (isSmall(value, minVal)) {
            minVal = value;
            result = cur;
        }
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (!visited[i]) {
            visited[i] = true;
            cur.push_back(i);
            permutation(cur);
            cur.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    for (int &num : nums) cin >> num;
    vector<int> cur;
    permutation(cur);
    for (int &i:result)
        cout << i << " ";
}