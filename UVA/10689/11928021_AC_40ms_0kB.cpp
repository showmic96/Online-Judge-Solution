// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD;

struct Matrix{

    ll x[2][2];

    void init(){

        memset(x , 0 , sizeof(x));

        for(int i=0;i<2;i++)x[i][i] = 1;
    }
};

Matrix mul(Matrix a , Matrix b)
{
    Matrix temp;

    memset(temp.x , 0 , sizeof(temp.x));

    for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            for(int k=0;k<2;k++){

                temp.x[i][k]+=a.x[i][j]*b.x[j][k];
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
    int t;
    scanf("%d",&t);
    while(t--){

        ll a , b , n , m;
        scanf("%lld %lld %lld %lld",&a , &b , &n , &m);

        Matrix temp;
        temp.x[0][0] = 1;
        temp.x[0][1] = 1;
        temp.x[1][0] = 1;
        temp.x[1][1] = 0;

        if(m==1)MOD = 10;
        if(m==2)MOD = 100;
        if(m==3)MOD = 1000;
        if(m==4)MOD = 10000;

        temp = BM(temp , n-1);

        ll ans = temp.x[0][0]*b+temp.x[0][1]*a;
        ans%=MOD;

        printf("%lld\n",ans);
    }
    return 0;
}
