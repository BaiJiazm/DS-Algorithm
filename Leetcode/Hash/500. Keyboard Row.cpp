class Solution {
	public:
		vector<string> findWords(vector<string>& words) {
			unordered_map<int, const char> key_to_row
			( {
				{ 'q', 0 }, { 'w', 0 }, { 'e', 0 }, { 'r', 0 }, { 't', 0 }, { 'y', 0 }, { 'u', 0 }, { 'i', 0 }, { 'o', 0 }, { 'p', 0 },
				{ 'a', 1 }, { 's', 1 }, { 'd', 1 }, { 'f', 1 }, { 'g', 1 }, { 'h', 1 }, { 'j', 1 }, { 'k', 1 }, { 'l', 1 },
				{ 'z', 2 }, { 'x', 2 }, { 'c', 2 }, { 'v', 2 }, { 'b', 2 }, { 'n', 2 }, { 'm', 2 }
			}
			);

			vector<string> output;

			for (const string &w : words) {
				char row = key_to_row[tolower(w[0])];

				bool one_row_flag = true;
				for (int i = 1; one_row_flag && i < w.length(); ++i)
					one_row_flag = row == key_to_row[tolower(w[i])];

				if (one_row_flag)
					output.push_back(w);
			}

			return output;
		}
};


class Solution {
	public:
		vector<string> findWords(vector<string>& words) {
			unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
			unordered_set<char> row2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
			unordered_set<char> row3 { 'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
			vector<unordered_set<char>> rows {row1, row2, row3};


			vector<string> validWords;
			for(int i=0; i<words.size(); ++i) {
				int row=0;

				for(int k=0; k<3; ++k) {
					if(rows[k].count((char)tolower(words[i][0])) > 0) row = k;
				}

				validWords.push_back(words[i]);
				for(int j=1; j<words[i].size(); ++j) {
					if(rows[row].count((char)tolower(words[i][j])) == 0) {
						validWords.pop_back();
						break;
					}
				}

			}
			return validWords;
		}
};
