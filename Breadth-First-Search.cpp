#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    string start;
    cin >> start;
    string goal = "ABCDEFGHIJKLMNO#";

    queue<pair<string,int>> q;
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == goal) {
            cout << dist << endl;
            break;
        }

        int pos;
        for (int i = 0; i < 16; i++) if (cur[i] == '#') pos = i;
        int row = pos / 4, col = pos % 4;

        if (row > 0) { string up = cur; swap(up[pos], up[pos-4]); if (!visited.count(up)) { visited.insert(up); q.push({up, dist+1}); } }
        if (row < 3) { string down = cur; swap(down[pos], down[pos+4]); if (!visited.count(down)) { visited.insert(down); q.push({down, dist+1}); } }
        if (col > 0) { string left = cur; swap(left[pos], left[pos-1]); if (!visited.count(left)) { visited.insert(left); q.push({left, dist+1}); } }
        if (col < 3) { string right = cur; swap(right[pos], right[pos+1]); if (!visited.count(right)) { visited.insert(right); q.push({right, dist+1}); } }
    }

    return 0;
}