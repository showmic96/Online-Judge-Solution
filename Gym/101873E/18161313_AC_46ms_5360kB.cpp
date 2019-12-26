// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct s{

    ll u , v;
    double w;
    s(ll _u , ll _v , double _w){

        u = _u;
        v = _v;
        w = _w;
    }
};

vector<s>v;
double dis[10005];
double ar[805][805];

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            ar[i][j] = 1e18;
        }
    }

    for(int i=0;i<m;i++){

        ll in1 , in2;
        double in3;
        scanf("%lld %lld %lf",&in1 , &in2 , &in3);
        ar[in1][in2] = min(ar[in1][in2] , -log(in3));
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ar[i][j]==1e18)continue;
            v.push_back(s(i , j , ar[i][j]));
        }
    }
    for(int i=0;i<=n;i++)dis[i] = 1e18;
    dis[1] = 0;
    for(int i=0;i<n-1;i++){

        for(int j=0;j<v.size();j++){

            int t1 = v[j].u;
            int t2 = v[j].v;
            double t3 = v[j].w;

            if(dis[t2]-0.00000001>dis[t1]+t3&&dis[t1]<1e17){

                dis[t2] = dis[t1]+t3;
            }
        }
    }

    for(int j=0;j<v.size();j++){

        int t1 = v[j].u;
        int t2 = v[j].v;
        double t3 = v[j].w;

        if(dis[t2]-0.00000001>dis[t1]+t3&&dis[t1]<1e17){

            printf("inadmissible\n");
            return 0;
        }
    }
    printf("admissible\n");


    return 0;
}
