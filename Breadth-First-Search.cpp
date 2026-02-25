#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string start;
    if (!(cin >> start)) return 0;
    string goal = "ABCDEFGHIJKLMNO#";
    if (start == goal) { cout << 0 << endl; return 0; }

    unordered_map<string,int> d1, d2;
    queue<string> q1, q2;
    d1[start] = 0; q1.push(start);
    d2[goal] = 0;  q2.push(goal);

    while (!q1.empty() && !q2.empty()) {
        if (q1.size() <= q2.size()) {
            int sz = q1.size();
            while (sz--) {
                string cur = q1.front(); q1.pop();
                int dist = d1[cur];
                int pos;
                for (int i = 0; i < 16; ++i) if (cur[i] == '#') pos = i;
                int r = pos / 4, c = pos % 4;
                if (r > 0) {
                    string nb = cur; swap(nb[pos], nb[pos-4]);
                    if (!d1.count(nb)) {
                        d1[nb] = dist + 1;
                        if (d2.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q1.push(nb);
                    }
                }
                if (r < 3) {
                    string nb = cur; swap(nb[pos], nb[pos+4]);
                    if (!d1.count(nb)) {
                        d1[nb] = dist + 1;
                        if (d2.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q1.push(nb);
                    }
                }
                if (c > 0) {
                    string nb = cur; swap(nb[pos], nb[pos-1]);
                    if (!d1.count(nb)) {
                        d1[nb] = dist + 1;
                        if (d2.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q1.push(nb);
                    }
                }
                if (c < 3) {
                    string nb = cur; swap(nb[pos], nb[pos+1]);
                    if (!d1.count(nb)) {
                        d1[nb] = dist + 1;
                        if (d2.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q1.push(nb);
                    }
                }
            }
        } else {
            int sz = q2.size();
            while (sz--) {
                string cur = q2.front(); q2.pop();
                int dist = d2[cur];
                int pos;
                for (int i = 0; i < 16; ++i) if (cur[i] == '#') pos = i;
                int r = pos / 4, c = pos % 4;
                if (r > 0) {
                    string nb = cur; swap(nb[pos], nb[pos-4]);
                    if (!d2.count(nb)) {
                        d2[nb] = dist + 1;
                        if (d1.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q2.push(nb);
                    }
                }
                if (r < 3) {
                    string nb = cur; swap(nb[pos], nb[pos+4]);
                    if (!d2.count(nb)) {
                        d2[nb] = dist + 1;
                        if (d1.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q2.push(nb);
                    }
                }
                if (c > 0) {
                    string nb = cur; swap(nb[pos], nb[pos-1]);
                    if (!d2.count(nb)) {
                        d2[nb] = dist + 1;
                        if (d1.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q2.push(nb);
                    }
                }
                if (c < 3) {
                    string nb = cur; swap(nb[pos], nb[pos+1]);
                    if (!d2.count(nb)) {
                        d2[nb] = dist + 1;
                        if (d1.count(nb)) { cout << d1[nb] + d2[nb] << endl; return 0; }
                        q2.push(nb);
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}