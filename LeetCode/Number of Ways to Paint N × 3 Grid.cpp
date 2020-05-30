class Solution {
public:
    typedef long long ll;
    ll dp[5005][3][3][3] , MOD = 1e9+7;
    
    ll f(int i , int f1 , int f2 , int f3 , int n){
        if(i==n)return 1;
        if(dp[i][f1][f2][f3]!=-1)return dp[i][f1][f2][f3];
        ll value = 0;
        for(int i1=0;i1<3;i1++){
            if(i1==f1)continue;
            for(int i2=0;i2<3;i2++){
                if(i2==f2||i1==i2)continue;
                for(int i3=0;i3<3;i3++){
                    if(i3==f3||i2==i3)continue;
                    value+=f(i+1 , i1 , i2 , i3 , n);
                    value%=MOD;
                }
            }
        }
        return dp[i][f1][f2][f3] = value;
    }
    
    int numOfWays(int n) {
        memset(dp , -1 , sizeof(dp));
        ll ans = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j)continue;
                for(int k=0;k<3;k++){
                    if(j==k)continue;
                    ans+=f(1 , i , j , k , n);
                    ans%=MOD;
                }
            }
        }
        return ans;
    }
};