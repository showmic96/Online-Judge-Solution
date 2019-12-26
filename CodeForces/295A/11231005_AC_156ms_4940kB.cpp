// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

int main(void)
{
    ll ar[MAX] , br[MAX];

    memset(ar , 0 ,sizeof(ar));
    memset(br , 0 ,sizeof(br));

    int n , m , k;
    scanf("%d %d %d",&n , &m , &k);

    vector<ll>v;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        //br[i] = in;
        v.push_back(in);
    }

    vector<pair < pair < int , int > , int > > work;

    for(int i=0;i<m;i++){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);

        work.push_back(make_pair(make_pair(in1 , in2) , in3));
    }

    for(int i=0;i<k;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        in1--;

        ar[in1]++;
        ar[in2]--;
    }

    for(int i=1;i<MAX;i++){

        ar[i]+=ar[i-1];
    }

    for(int i=0;i<m;i++){

        int u = work[i].first.first;
        int v = work[i].first.second;
        int w = work[i].second;

        u--;

        br[u]+=ar[i]*w;
        br[v]-=ar[i]*w;
    }

    for(int i=1;i<MAX;i++){

        br[i]+=br[i-1];
    }

    for(int i=0;i<n;i++){

        if(i>0)printf(" ");
        printf("%lld",br[i]+v[i]);
    }

    printf("\n");

    return 0;
}
