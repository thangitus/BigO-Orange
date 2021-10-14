#include <bits/stdc++.h>


using namespace std;

struct Point {
    int x, y;
};

bool sortX(Point &p1, Point &p2) {
    return p1.x < p2.x;
}

bool sortY(Point &p1, Point &p2) {
    return p1.y < p2.y;
}

double distance(Point &p1, Point &p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

double bruteForce(vector<Point> &points, int left, int right) {
    auto minDist = DBL_MAX;
    for (int i = left; i <= right; i++)
        for (int j = i + 1; j < right; j++)
            minDist = min(minDist, distance(points[i], points[j]));
    return minDist;
}

double stripClosest(vector<Point> &points, int left, int mid, int right, double minDist) {
    Point pointMid = points[mid];
    vector<Point> split;
    for (int i = left; i <= right; i++)
        if (abs(points[i].x - pointMid.x) <= minDist)
            split.push_back(points[i]);
    sort(split.begin(), split.end(), sortY);
    auto smallest = DBL_MAX;
    auto n = split.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (split[j].y - split[i].y >= minDist) break;
            double d = distance(split[i], split[j]);
            smallest = min(smallest, d);
        }
    return smallest;
}

double minimalDistance(vector<Point> &points, int left, int right) {
    if (right - left <= 3) return bruteForce(points, left, right);
    int mid = (right + left) / 2;
    double leftDist = minimalDistance(points, left, mid);
    double rightDist = minimalDistance(points, mid + 1, right);
    double minDist = min(leftDist, rightDist);
    return min(minDist, stripClosest(points, left, mid, right, minDist));
}

int main() {
    int n;
    do {
        cin >> n;
        if (!n) break;
        vector<Point> points(n);
        for (auto &point:points) cin >> point.x >> point.y;
        sort(points.begin(), points.end(), sortX);
        auto result = minimalDistance(points, 0, n - 1);
        if (result >= 10000) cout << "INFINITY\n";
        else cout << fixed << setprecision(4) << result << endl;
    } while (true);
}