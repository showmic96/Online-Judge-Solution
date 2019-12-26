// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bitset<100005>bs;
ll ar[100005];

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);

    bs[0] = 1;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        bs|=bs<<in;
    }

    memset(ar , 0 , sizeof(ar));

    for(int i=1;i<=100005;i++)ar[i] = ar[i-1]+bs[i];

    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        printf("%lld\n",ar[in2]-ar[in1-1]);
    }

    return 0;
}
