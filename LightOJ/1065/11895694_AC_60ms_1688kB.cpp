// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD;
ll a , b , n , m;

struct Matrix{

    ll x[2][2];

    void init(){
        x[0][0] = 1;
        x[0][1] = 0;
        x[1][0] = 0;
        x[1][1] = 1;
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
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld %lld %lld",&a , &b , &n, &m);

        if(m==1)MOD = 10;
        if(m==2)MOD = 100;
        if(m==3)MOD = 1000;
        if(m==4)MOD = 10000;

        Matrix temp;
        temp.x[0][0] = 1;
        temp.x[0][1] = 1;
        temp.x[1][0] = 1;
        temp.x[1][1] = 0;

        temp = BM(temp , n-1);

        printf("Case %d: %lld\n",++c, (temp.x[0][0]*b+temp.x[0][1]*a)%MOD);
    }
    return 0;
}
