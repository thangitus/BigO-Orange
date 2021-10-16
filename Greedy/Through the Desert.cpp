#include <bits/stdc++.h>


using namespace std;

int main() {
    string line;
    double curTankVolume = 0.0, maxTankVolume = 0.0;
    int prevPos = 0, consumption = 0, leak = 0;

    while (getline(cin, line)) {
        if (line == "0 Fuel consumption 0") break;
        istringstream input(line);
        int curPos, value;
        string s, tmp;
        input >> curPos >> s;
        if (s == "Fuel" || s == "Gas") input >> tmp;
        input >> value;

        curTankVolume += leak * (curPos - prevPos);
        curTankVolume += (consumption / 100.0) * (curPos - prevPos);
        maxTankVolume = max(curTankVolume, maxTankVolume);

        if (s == "Fuel") consumption = value;
        else if (s == "Leak") leak++;
        else if (s[0] == 'M') leak = 0;
        else if (s == "Gas") curTankVolume = 0.0;
        prevPos = curPos;
        if (s == "Goal") {
            cout << fixed << setprecision(3) << maxTankVolume << endl;
            curTankVolume = maxTankVolume = prevPos = consumption = leak = 0;
        }
    }
}