// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[333][333][333];
ll ar[333];
int d , m;
int n , q;

ll f(int i , int j , int mod)
{
    if(j==m){

        if(mod==0)return 1;
        else return 0;
    }

    if(i==n)return 0;

    if(dp[i][j][mod]!=-1)return dp[i][j][mod];

    ll value = 0;

    value += f(i+1 , j+1 , (mod+ar[i])%d);
    value += f(i+1 , j , mod%d);

    return dp[i][j][mod] = value;
}

int main(void)
{

    int c1 = 0;
    while(cin >> n >> q){

        if(!n&&!q)break;

        for(int i=0;i<n;i++)cin >> ar[i];
        int c2 =0 ;
        printf("SET %d:\n",++c1);
        while(q--){
            memset(dp , -1 , sizeof(dp));

            cin >> d >> m;
            printf("QUERY %d: ",++c2);
            cout << f(0 , 0 , 0) << endl;
        }
    }
    return 0;
}
