// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 10007;

struct Matrix{

    ll x[4][4];

    void init(){

        memset(x , 0 , sizeof(x));
        for(int i=0;i<4;i++)x[i][i] = 1;
    }
}temp;

Matrix mul(Matrix a , Matrix b)
{
    Matrix temp;
    memset(temp.x , 0 , sizeof(temp.x));

    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){

            for(int k=0;k<4;k++){

                temp.x[i][k] += a.x[i][j]*b.x[j][k];
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

    while(n){

        if(n&1){

            ret = mul(ret , a);
        }

        a = mul(a , a);
        n/=2;
    }

    return ret;
}

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);
    while(t--){

        ll n , a , b , c;
        scanf("%lld %lld %lld %lld",&n, &a , &b , &c);

        a%=MOD , b%=MOD , c%=MOD;

        Matrix t;

        memset(t.x , 0 , sizeof(t.x));

        t.x[0][0] = a;
        t.x[0][2] = b;
        t.x[0][3] = 1;
        t.x[1][0] = 1;
        t.x[2][1] = 1;
        t.x[3][3] = 1;

        t = BM(t , n-2);

        if(n<=2)printf("Case %d: %lld\n",++tc , 0LL);
        else printf("Case %d: %lld\n",++tc , (t.x[0][3]*c)%MOD);
    }
    return 0;
}
