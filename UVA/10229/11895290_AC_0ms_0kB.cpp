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
}temp;

Matrix mul(Matrix a , Matrix b)
{
    Matrix sum;
    memset(sum.x , 0 , sizeof(sum.x));

    for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            for(int k=0;k<2;k++){

                sum.x[i][k]+=a.x[i][j]*b.x[j][k];
                sum.x[i][k]%=MOD;
            }
        }
    }

    return sum;
}

Matrix BM(Matrix a , ll n)
{
    Matrix ret;
    ret.init();

    if(n==0)return ret;
    if(n==1)return a;


    while(n){

        if(n%2){

            temp = ret;
            ret = mul(ret , a);
        }

        n/=2;

        a = mul(a , a);
    }

    return ret;
}

int main(void)
{
    ll a , b;
    while(scanf("%lld %lld",&a , &b)==2){

        MOD = (1<<b);

        Matrix temp;
        temp.x[0][0] = 1;
        temp.x[0][1] = 1;
        temp.x[1][0] = 1;
        temp.x[1][1] = 0;

        printf("%lld\n",BM(temp, a).x[0][1]);
    }
    return 0;
}
