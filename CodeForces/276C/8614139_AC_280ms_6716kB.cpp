// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , q;
    scanf("%d %d",&n , &q);//cin >> n >> q;
    long long ar[n] , br[n+100] , m[n];

    memset(br , 0 , sizeof(br));

    for(int i=0;i<n;i++){

        scanf("%lld",&ar[i]);//cin >> ar[i];
    }

    for(int i=0;i<q;i++){

        long long in1 , in2;
        scanf("%lld %lld",&in1 , &in2);//cin >> in1 >> in2;

        br[in1-1]++;
        br[in2]--;
    }

    long long v = 0;

    for(int i=0;i<n;i++){

        v+=br[i];
        m[i] = v;
    }

    long long sum = 0;

    sort(m , m+n);
    sort(ar , ar+n);

    for(int i=0;i<n;i++){

        sum+=(ar[i]*m[i]);
    }

    printf("%lld\n",sum);//cout << sum << endl;

    return 0;
}
