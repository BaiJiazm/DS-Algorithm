/* ********************************
���ӣ�https://www.nowcoder.com/questionTerminal/74475ee28edb497c8aa4f8c370f08c30
��Դ��ţ����
* ********************************/

#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string str;
    while (cin >> str){
        string str1;
        cin >> str1;
        int a=0, b = 0;
        while (a < str.length()){
            if (str[a++] == str1[b])
                b++;
 
        }
        if (b == str1.length())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
 
}
