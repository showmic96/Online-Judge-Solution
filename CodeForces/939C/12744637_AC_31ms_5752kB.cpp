// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[300005];

int main(void)
{
    memset(ar , 0 , sizeof(ar));

    int n;
    scanf("%d",&n);
    vector<ll>v;
    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);

        v.push_back(in);
    }

    for(int i=1;i<=2*n+10;i++){

        ar[i] = ar[i-1]+v[(i-1)%n];

    }

    int s , f;
    scanf("%d %d",&s , &f);

    int temp = f-s;
    double ans = 1e19 , mx = 0;

    for(int i=1;i<=n;i++){

        double t = ar[n+f-i]-ar[n+s-i];

        if(t>mx){

            mx = t;
            ans = i;
        }

    }

    printf("%lld\n",(ll)ans);

    return 0;
}
