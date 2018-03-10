#include<iostream> 
#include<string>
#include<map>  
#include<algorithm>
using namespace std;
int main()
{
	int index, len, maxcnt;
	string line;
	string word, ans;
	map<string, int>words;
	getline(cin, line);
	len = line.size();
	line[len++] = '.';/*用于处理可能123 123 e 123这样结尾的少数一个的问题*/
	for (index = 0, maxcnt = 0, ans = "\0"; index < len; index++)
	{
		if (isalpha(line[index]) || isdigit(line[index]))
			word += !isdigit(line[index]) && isupper(line[index]) ? line[index] - 'A' + 'a' : line[index];/*判断顺序不能换*/
		else  if (!word.empty())
		{
			words[word]++;
			if (words[word] > maxcnt || words[word] == maxcnt&&word < ans)
			{
				maxcnt = words[word];
				ans = word;
			}
			word.erase();
		}
	}
	cout << ans << " " << maxcnt << endl;
	return 0;
}
