#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int pos;
    for (int i = 0; i < 16; i++) if (s[i] == '#') pos = i;
    int row = pos / 4, col = pos % 4;
    if (row > 0) cout << "UP" << endl;
    if (row < 3) cout << "DOWN" << endl;
    if (col > 0) cout << "LEFT" << endl;
    if (col < 3) cout << "RIGHT" << endl;
    return 0;
}