class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9+7;
    ll dp[33][1005] , n , lim;
    
    ll f(int i , int tot){
        if(i==n){
            if(tot==0)return 1;
            return 0;
        }
        if(tot<0)return 0;
        if(dp[i][tot]!=-1)return dp[i][tot];
        ll value = 0;
        for(int j=1;j<=lim;j++){
            value+=f(i+1 , tot-j);
        }
        return dp[i][tot] = value%MOD;
    }
    
    int numRollsToTarget(int d, int l, int target) {
        n = d;
        lim = l;
        memset(dp, -1, sizeof(dp));
        ll ans = f((int)0 , target);
        return (int)ans;
    }
};
