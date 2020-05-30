class Solution {
public:
    typedef long long ll;
    ll dp[20005][5], MOD = 1e9+7;
    
    ll f(int i , int last , int n){
        if(i==n)return 1;
        if(dp[i][last]!=-1)return dp[i][last];
        ll value = 0;
        if(last==0){
            value+=f(i+1 , 1 , n);
        }
        if(last==1){
            value+=f(i+1 , 0 , n);
            value+=f(i+1 , 2 , n);
        }
        if(last==2){
            value+=f(i+1 , 0 , n);
            value+=f(i+1 , 1 , n);
            value+=f(i+1 , 3 , n);
            value+=f(i+1 , 4 , n);
        }
        if(last==3){
            value+=f(i+1 , 2 , n);
            value+=f(i+1 , 4 , n);
        }
        if(last==4){
            value+=f(i+1 , 0 , n);
        }
        return dp[i][last] = value%MOD;
    }
    
    int countVowelPermutation(int n) {
        memset(dp , -1 , sizeof(dp));
        ll ans = 0;
        for(int i=0;i<5;i++){
            ans+=f(1 , i , n);
            ans%=MOD;
        }
        return ans;
    }
};