class Solution {
public:
    int dp[100005];
    int smallestRepunitDivByK(int K) {
        int cnt = 0 , now = 0;
        while(true){
            cnt++;
            now*=10;
            now+=1;
            now%=K;
            if(dp[now]==1)return -1;
            dp[now] = 1;
            if(now==0)break;
        }
        return cnt;
    }
};