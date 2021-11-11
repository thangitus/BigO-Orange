#include <bits/stdc++.h>

using namespace std;

struct Block {
    int dimension[3];

    Block(int x, int y, int z) {
        dimension[0] = x;
        dimension[1] = y;
        dimension[2] = z;
    }

    bool CanStack(const struct Block &other) {
        return dimension[0] < other.dimension[0] && dimension[1] < other.dimension[1];
    }

    bool operator<(const Block &x) const {
        for (int i = 0; i < 3; ++i) {
            if (dimension[i] > x.dimension[i])
                return true;
            else if (dimension[i] < x.dimension[i])
                return false;
        }
        return true;
    }
};

void GetBlocks(vector<Block> &blocks, int a, int b, int c) {
    int arr[] = {a, b, c};
    sort(arr, arr + 3);
    do {
        blocks.emplace_back(arr[0], arr[1], arr[2]);
    } while (next_permutation(arr, arr + 3));
}

int LIS(vector<Block> &blocks) {
    int result = 0;
    vector<int> height(blocks.size());
    for (int i = 0; i < blocks.size(); ++i) {
        height[i] = blocks[i].dimension[2];
        for (int j = 0; j < i; ++j) {
            if (blocks[i].CanStack(blocks[j]))
                height[i] = max(height[i], height[j] + blocks[i].dimension[2]);
        }
        result = max(result, height[i]);
    }
    return result;
}

int main() {
    int n, a, b, c, cases = 1;
    cin >> n;

    while (n != 0) {
        vector<Block> blocks;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c;
            GetBlocks(blocks, a, b, c);
        }
        sort(blocks.begin(), blocks.end());
        cout << "Case " << cases++ << ": maximum height = " << LIS(blocks) << endl;
        cin >> n;
    }

    return 0;
}