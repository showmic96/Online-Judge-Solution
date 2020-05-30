class Solution {
public:
    int dp[10005];
    bool cmp(vector<int>A, vector<int>B){
        if(A[0]==B[0]){
            return A[1]<B[1];
        }
        return A[0]<B[0];
    }
    int f(int i, vector<vector<int>>& v){
        if(i==v.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int value = 0;
        for(int j=i+1;j<v.size();j++){
            if(v[i][0]<v[j][0]&&v[i][1]<v[j][1])value = max(value , f(j, v)+1);
        }
        return dp[i] = value;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        memset(dp , -1 , sizeof(dp));
        int ans = 0;
        for(int i=0;i<envelopes.size();i++){
            ans = max(ans , f(i, envelopes)+1);
        }
        return ans;
    }
};