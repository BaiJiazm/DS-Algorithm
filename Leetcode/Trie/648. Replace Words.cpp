#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie** child;
    bool flag;
    Trie(){
        child=NULL;
        flag=false;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie root;
        for(int i=0; i<dict.size(); ++i){
            insert(&root, dict[i]);
        }
        string res;
        sentence+=' ';
        for(int begin=0, end; begin<sentence.length(); begin=end+1){
            end=sentence.find(' ', begin);
            string word=sentence.substr(begin, end-begin);
            res+=find(&root, word);
            res+=' ';
        }
        res.pop_back();
        return res;
    }
    void insert(Trie* root, string word){
        for(int i=0; i<word.length(); ++i){
            if(root->child==NULL){
                root->child=new Trie*[26];
                memset(root->child, 0, 26*sizeof(Trie*));
            }
            if(root->child[word[i]-'a']==NULL){
                root->child[word[i]-'a']=new Trie();
            }
            root=root->child[word[i]-'a'];
        }
        root->flag=true;
    }
    string find(Trie* root, string word){
        int i=0;
        for(; i<word.length()&&root&&!root->flag; ++i){
            root=root->child[word[i]-'a'];
        }
        if(root&&root->flag){
            return word.substr(0, i);
        }
        return word;
    }
};

int main(){
    vector<string>dict={"cat", "bat", "rat"};
    string s="the cattle was rattled by the battery";
    Solution S;
    cout<<S.replaceWords(dict, s)<<endl;
    return 0;
}