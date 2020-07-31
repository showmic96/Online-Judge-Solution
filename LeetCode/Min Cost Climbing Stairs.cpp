class Solution {
public:
    vector<int>v;
    int dp[1005];
    int f(int now){
        if(now>=v.size())return 0;
        if(dp[now]!=-1)return dp[now];
        int value = f(now+1)+v[now];
        value = min(value , f(now+2)+v[now]);
        return dp[now] = value;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        v = cost;
        memset(dp , -1 , sizeof(dp));
        return min(f(0), f(1));
    }
};
