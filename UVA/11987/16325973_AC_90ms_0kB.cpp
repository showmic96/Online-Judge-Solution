// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 200005;

ll par[MAX+9] , sum[MAX+9] , ele[MAX+9];

ll Find(ll x)
{
    if(x==par[x])return x;
    return par[x] = Find(par[x]);
}

void Union(ll x, ll y)
{
    ll px = Find(x);
    ll py = Find(y);

    if(px==py)return ;

    par[px] = py;
    ele[py]+=ele[px];
    sum[py]+=sum[px];
}

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n , &m)==2){

        for(int i=1;i<=n;i++){

            par[i] = i+n+1;
            par[i+n+1] = i+n+1;
            sum[i+n+1] = i;
            ele[i+n+1] = 1;
        }

        while(m--){

            int in;
            scanf("%d",&in);

            if(in==1){

                int in1 , in2;
                scanf("%d %d",&in1 , &in2);
                Union(in1 , in2);
            }
            else if(in==2){

                int in1 , in2;
                scanf("%d %d",&in1 , &in2);

                int px = Find(in1);
                int py = Find(in2);

                if(px==py)continue;

                ele[px]--;
                ele[py]++;

                sum[px]-=in1;
                sum[py]+=in1;

                par[in1] = py;
            }
            else{

                int val;
                scanf("%d",&val);
                printf("%lld %lld\n",ele[Find(val)] , sum[Find(val)]);
            }
        }
    }
    return 0;
}
