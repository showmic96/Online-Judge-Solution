// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1000000007;

struct Matrix{

    ll x[2][2];

    void init(){

        memset(x , 0 , sizeof(x));

        for(int i=0;i<2;i++)x[i][i] = 1;
    }

} temp;

Matrix mul(Matrix a , Matrix b)
{
    Matrix temp;
    memset(temp.x , 0 , sizeof(temp.x));

    for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            for(int k=0;k<2;k++){

                temp.x[i][k]+= a.x[i][j]*b.x[j][k];
                temp.x[i][k]%=MOD;
            }
        }
    }

    return temp;
}

Matrix BM(Matrix a , ll n)
{
    Matrix ret;
    ret.init();

    if(n==0)return ret;
    if(n==1)return a;

    while(n){

        if(n%2){

            ret = mul(ret , a);
        }

        a = mul(a , a);
        n/=2;
    }

    return ret;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll n , m;
        scanf("%lld %lld",&n, &m);

        Matrix a , b;
        a.x[0][0] = 1 , a.x[0][1] = 1 , a.x[1][0] = 1 , a.x[1][1] = 0;
        b.x[0][0] = 1 , b.x[0][1] = 1 , b.x[1][0] = 1 , b.x[1][1] = 0;

        ll ans1 = BM(a , n+1).x[0][1];
        ll ans2 = BM(b , m+2).x[0][1];

        ll ans = (ans2-ans1)+MOD;
        ans%=MOD;

        printf("%lld\n",ans);

    }
    return 0;
}
