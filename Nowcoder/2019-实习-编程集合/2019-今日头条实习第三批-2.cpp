#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
//	freopen("test21.txt", "r", stdin);
//    std::ios::sync_with_stdio(false);
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
    	getchar();
        unordered_set<string>set;
        string str;
        while (m--) {
            getline(cin, str);
            set.insert(str);
        }
        getchar();
        while (n--){
            int flag=-1;
            getline(cin, str);
            str.push_back(0);
            for (int i = 0; i < str.length(); ++i) {
                unsigned char uch = (unsigned char)str[i];
                if (uch >> 6 != 2 && i) {
                    if (set.count(str.substr(0, i))) {
                        flag = 1;
                        break;
                    }
                }
            }
            printf("%d\n", flag);
        }
        printf("\n");
    }
    return  0;
}
