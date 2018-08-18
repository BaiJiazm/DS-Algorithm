#include <iostream>
#include <string>
using namespace std;

int main() {
//	freopen("test13.c", "r", stdin);
    int commentCount = 0;
    int index;
    int state = 0;
    string line;
    while (getline(cin, line)) {
        for (index = 0; index < line.length(); ++index) {
            char ch1 = line[index];
            char ch2 = index < line.length() ? line[index + 1] : 0;
            if (state == 0) {
                if (ch1 == '/'&&ch2 == '/') {
                    ++commentCount;
                    break;
                }
                else if (ch1 == '/'&&ch2 == '*') {
                    state = 2;
                    ++commentCount;
                    ++index;
                }
                else if (ch1 == '\"') {
                    state = 3;
                }
            }
            else if (state == 2) {
                if (ch1 == '*'&&ch2 == '/') {
                    ++index;
                    state = 0;
                }
            }
            else if (state == 3) {
                if (ch1 == '\\') {
                    ++index;
                }
                else if (ch1 == '"') {
                    state = 0;
                }
            }
        }
    }
    cout << commentCount << endl;
    return  0;
}
