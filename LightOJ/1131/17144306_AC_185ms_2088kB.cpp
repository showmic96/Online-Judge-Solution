// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9+9;

struct Matrix{

    ll x[6][6];

    void init(){

        memset(x , 0 , sizeof(x));
        for(int i=0;i<6;i++)x[i][i] = 1;
    }
};

Matrix mul(Matrix a , Matrix b)
{
    Matrix temp;

    memset(temp.x , 0 , sizeof(temp.x));

    for(int i=0;i<6;i++){

        for(int j=0;j<6;j++){

            for(int k=0;k<6;k++){

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
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll a1 , b1 , c1 , a2 , b2 , c2 , f0 , f1 , f2 , g0 , g1 , g2;
        scanf("%lld %lld %lld",&a1 , &b1 , &c1);
        scanf("%lld %lld %lld",&a2 , &b2 , &c2);
        scanf("%lld %lld %lld",&f0 , &f1 , &f2);
        scanf("%lld %lld %lld",&g0 , &g1 , &g2);
        scanf("%lld",&MOD);

        Matrix temp;

        memset(temp.x , 0 , sizeof(temp.x));
        temp.x[0][0] = a1%MOD;
        temp.x[0][1] = b1%MOD;
        temp.x[0][5] = c1%MOD;
        temp.x[1][0] = 1;
        temp.x[2][1] = 1;
        temp.x[3][2] = c2%MOD;
        temp.x[3][3] = a2%MOD;
        temp.x[3][4] = b2%MOD;
        temp.x[4][3] = 1;
        temp.x[5][4] = 1;

        printf("Case %d:\n",++c);
        int q;
        scanf("%d",&q);
        while(q--){

            ll n;
            scanf("%lld",&n);

            if(n<3){

                if(n==0)printf("%lld %lld\n",f0%MOD , g0%MOD);
                if(n==1)printf("%lld %lld\n",f1%MOD , g1%MOD);
                if(n==2)printf("%lld %lld\n",f2%MOD , g2%MOD);
                continue;
            }


            Matrix now = BM(temp , n-2);

            ll ans1 = (now.x[0][0]*f2)%MOD+(now.x[0][1]*f1)%MOD+(now.x[0][2]*f0)%MOD;
            ans1 += (now.x[0][3]*g2)%MOD+(now.x[0][4]*g1)%MOD+(now.x[0][5]*g0)%MOD;

            ll ans2 = (now.x[3][0]*f2)%MOD+(now.x[3][1]*f1)%MOD+(now.x[3][2]*f0)%MOD;
            ans2 += (now.x[3][3]*g2)%MOD+(now.x[3][4]*g1)%MOD+(now.x[3][5]*g0)%MOD;

            printf("%lld %lld\n",ans1%MOD , ans2%MOD);
        }
    }
    return 0;
}
