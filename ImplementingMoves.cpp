#include <iostream>
using namespace std;

int main() {
    string s, move;
    cin >> s >> move;
    int pos;
    for (int i = 0; i < 16; i++) if (s[i] == '#') pos = i;
    int row = pos / 4, col = pos % 4;
    if (move == "UP" && row > 0) swap(s[pos], s[pos - 4]);
    if (move == "DOWN" && row < 3) swap(s[pos], s[pos + 4]);
    if (move == "LEFT" && col > 0) swap(s[pos], s[pos - 1]);
    if (move == "RIGHT" && col < 3) swap(s[pos], s[pos + 1]);
    for (int i = 0; i < 16; i++) {
        cout << s[i] << " ";
        if ((i + 1) % 4 == 0) cout << endl;
    }
    return 0;
}