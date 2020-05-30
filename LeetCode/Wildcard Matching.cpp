class Solution {
public:
    bool dp[2005][2005];
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        dp[0][0] = true;
        for(int i=0;i<m;i++){
            if(p[i]=='*')dp[0][i+1] = dp[0][i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[j]=='*')
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
                else if(p[j]=='?')
                    dp[i+1][j+1] = dp[i][j];
                else if(s[i]==p[j])
                    dp[i+1][j+1] = dp[i][j];
            }
        }
        return dp[n][m];
    }
};