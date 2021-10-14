#include <bits/stdc++.h>


using namespace std;
typedef long long long2;
struct Point {
    long2 x, y;
};

bool sortX(Point &p1, Point &p2) {
    return p1.x < p2.x;
}

bool sortY(Point &p1, Point &p2) {
    return p1.y < p2.y;
}

long2 distance(Point &p1, Point &p2) {
    long2 x = p1.x - p2.x;
    long2 y = p1.y - p2.y;
    return x * x + y * y;
}

long2 bruteForce(vector<Point> &points, int left, int right) {
    auto minDist = LLONG_MAX;
    for (int i = left; i < right; i++)
        for (int j = i + 1; j <= right; j++)
            minDist = min(minDist, distance(points[i], points[j]));
    return minDist;
}

long2 stripClosest(vector<Point> &points, int left, int mid, int right, long2 minDist) {
    Point pointMid = points[mid];
    vector<Point> split;
    for (int i = left; i <= right; i++)
        if (pow(points[i].x - pointMid.x, 2) <= minDist)
            split.push_back(points[i]);
    sort(split.begin(), split.end(), sortY);
    auto smallest = LLONG_MAX;
    auto n = split.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (pow(split[j].y - split[i].y, 2) >= minDist) break;
            long2 d = distance(split[i], split[j]);
            smallest = min(smallest, d);
        }
    return smallest;
}

long2 minimalDistance(vector<Point> &points, int left, int right) {
    if (right - left < 3) return bruteForce(points, left, right);
    int mid = (right + left) / 2;
    long2 leftDist = minimalDistance(points, left, mid);
    long2 rightDist = minimalDistance(points, mid + 1, right);
    long2 minDist = min(leftDist, rightDist);
    return min(minDist, stripClosest(points, left, mid, right, minDist));
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> points[i].y;
        points[i].x = i;
        points[i].y += points[i - 1].y;
    }
    sort(points.begin() + 1, points.end(), sortX);
    auto result = minimalDistance(points, 1, n);
    cout << result << endl;
}