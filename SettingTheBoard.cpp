#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 16; i++) {
        cout << s[i] << " ";
        if ((i + 1) % 4 == 0) cout << endl;
    }
    return 0;
}