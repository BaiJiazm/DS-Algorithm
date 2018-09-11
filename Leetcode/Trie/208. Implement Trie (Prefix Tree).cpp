class TrieNode {
	public:
		TrieNode *next[26];
		bool is_word;

		// Initialize your data structure here.
		TrieNode(bool b = false) {
			memset(next, 0, sizeof(next));
			is_word = b;
		}
};

class Trie {
		TrieNode *root;
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string s) {
			TrieNode *p = root;
			for(int i = 0; i < s.size(); ++ i) {
				if(p -> next[s[i] - 'a'] == NULL)
					p -> next[s[i] - 'a'] = new TrieNode();
				p = p -> next[s[i] - 'a'];
			}
			p -> is_word = true;
		}

		// Returns if the word is in the trie.
		bool search(string key) {
			TrieNode *p = find(key);
			return p != NULL && p -> is_word;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			return find(prefix) != NULL;
		}

	private:
		TrieNode* find(string key) {
			TrieNode *p = root;
			for(int i = 0; i < key.size() && p != NULL; ++ i)
				p = p -> next[key[i] - 'a'];
			return p;
		}
};
