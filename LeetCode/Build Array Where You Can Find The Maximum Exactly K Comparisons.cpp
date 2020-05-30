class Solution {
public:
    typedef long long ll;
    ll dp[55][105][55] , MOD = 1e9+7;
    ll f(int i , int last , int tot , int n , int m , int k){
        if(i==n){
            if(tot==k)return 1;
            return 0;
        }
        if(dp[i][last][tot]!=-1)return dp[i][last][tot];
        ll value = last*f(i+1 , last, tot, n , m , k);
        value%=MOD;
        for(int j=last+1;j<=m;j++){
            value+=f(i+1 , j , tot+1, n , m , k);
            value%=MOD;
        }
        return dp[i][last][tot] = value;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp , -1 , sizeof(dp));
        return f(0 , 0 , 0 , n , m , k);
    }
};