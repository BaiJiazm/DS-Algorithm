/*
���ӣ�https://www.nowcoder.com/questionTerminal/ca5c9ba9ebac4fd5ae9ba46114b0f476
��Դ��ţ����
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;
 
 
int main() {
    string str;
    set<string> datas;
    while (cin >> str) {
        datas.insert(str);
    }
    cout << datas.size() << endl;
    return 0;
}
