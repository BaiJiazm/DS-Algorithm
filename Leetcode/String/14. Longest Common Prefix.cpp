class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int maxlen=0;
        for (int i=0;i<strs.size();++i)
            maxlen=max(maxlen,(int)strs[i].length());
        for (int i=0;i<maxlen;++i){
            char ch=strs[0][i];
            for (int j=1;j<strs.size();++j)
                if (strs[j][i]!=ch)
                   return ans;
            ans+=ch;
        }
        return ans;
    }
};
