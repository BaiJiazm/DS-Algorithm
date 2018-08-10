class Solution {
public:
    vector<vector<vector<string> > >dp;
    int m, n;
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        m=nums1.size(), n=nums2.size();
        dp=vector<vector<vector<string>>>(m+1, vector<vector<string>>(n+1, vector<string>(k, "")));
        string str=solve(nums1, nums2, 0, 0, k);
        vector<int>ans;
        for (auto& a:str){
            ans.push_back(a-'0');
        }
        return ans;
    }

    string solve(vector<int>& nums1, vector<int>& nums2, int i, int j, int k){
        if(k<=0||m-i+n-j<k)
            return "";
        if(!dp[i][j][k].empty()){
            return dp[i][j][k];
        }
        string s1, s2, s3, rs;
        if(i>=m||j<n&&nums1[i]<nums2[j]){
            s1=to_string(nums2[j])+solve(nums1, nums2, i, j+1, k-1);
        }
        if(j>=n||i<m&&nums1[i]>=nums2[j]){
            s2=to_string(nums1[i])+solve(nums1, nums2, i+1, j, k-1);
        }
        s3=solve(nums1, nums2, min(i+1, m), min(j+1, n), k);

        if(s1.length()==k)
            rs=max(rs, s1);
        if(s2.length()==k)
            rs=max(rs, s2);
        if(s3.length()==k)
            rs=max(rs, s3);
        return dp[i][j][k]=rs;
    }
};