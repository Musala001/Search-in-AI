#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string state;
    int g;
    bool operator<(const Node &other) const {
        return g > other.g;
    }
};

int h(string s) {
    string goal = "ABCDEFGHIJKLMNO#";
    int dist = 0;
    for (int i = 0; i < 16; i++) {
        if (s[i] != '#') {
            int goal_pos = goal.find(s[i]);
            dist += abs(i/4 - goal_pos/4) + abs(i%4 - goal_pos%4);
        }
    }
    return dist;
}

int main() {
    string start;
    cin >> start;
    string goal = "ABCDEFGHIJKLMNO#";
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    set<string> visited;
    pq.push({h(start), start});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        string cur = p.second;
        int g = p.first - h(cur);
        if (cur == goal) { cout << g << endl; break; }
        if (visited.count(cur)) continue;
        visited.insert(cur);
        int pos;
        for (int i = 0; i < 16; i++) if (cur[i] == '#') pos = i;
        int row = pos / 4, col = pos % 4;
        if (row > 0) { string up = cur; swap(up[pos], up[pos-4]); if (!visited.count(up)) pq.push({g+1+h(up), up}); }
        if (row < 3) { string down = cur; swap(down[pos], down[pos+4]); if (!visited.count(down)) pq.push({g+1+h(down), down}); }
        if (col > 0) { string left = cur; swap(left[pos], left[pos-1]); if (!visited.count(left)) pq.push({g+1+h(left), left}); }
        if (col < 3) { string right = cur; swap(right[pos], right[pos+1]); if (!visited.count(right)) pq.push({g+1+h(right), right}); }
    }
    return 0;
}