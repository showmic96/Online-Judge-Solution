// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9+9;

struct Matrix{

    ll x[3][3];

    void init(){

        memset(x , 0 , sizeof(x));
        for(int i=0;i<3;i++)x[i][i] = 1;
    }
};

Matrix mul(Matrix a , Matrix b)
{
    Matrix temp;

    memset(temp.x , 0 , sizeof(temp.x));

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            for(int k=0;k<3;k++){

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
    ll n;

    while(scanf("%lld",&n)==1){

        if(n==0)break;
        if(n<3){

            if(n==1)printf("0\n");
            if(n==2)printf("1\n");
            continue;
        }
        Matrix temp;

        temp.x[0][0] = 1;
        temp.x[0][1] = 1;
        temp.x[0][2] = 1;
        temp.x[1][0] = 1;
        temp.x[1][1] = 0;
        temp.x[1][2] = 0;
        temp.x[2][0] = 0;
        temp.x[2][1] = 1;
        temp.x[2][2] = 0;

        temp = BM(temp , n-3);

        printf("%lld\n",(temp.x[0][0]*2LL+temp.x[0][1])%MOD);
    }
    return 0;
}
