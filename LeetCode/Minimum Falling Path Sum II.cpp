class Solution {
public:
    int dp[205][205];
    int f(int i , int last, vector<vector<int>>& arr){
        if(i==arr.size())return 0;
        if(dp[i][last]!=-1)return dp[i][last];
        int ans = 1e9;
        for(int j=0;j<arr[i].size();j++){
            if(j==last)continue;
            ans = min(ans , f(i+1 , j , arr)+arr[i][j]);
        }
        return dp[i][last] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        int ans = 1e9;
        memset(dp , -1 , sizeof(dp));
        for(int i=0;i<arr[0].size();i++){
            ans = min(ans , f(1 , i , arr)+arr[0][i]);
        }
        return ans;
    }
};