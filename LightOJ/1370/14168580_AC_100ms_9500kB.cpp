// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 9;

int phi[MAX+9];
int ans[MAX+9];

void seive()
{
    for(int i=0;i<=MAX;i++)phi[i] = i;

    phi[1] = 1;

    for(int i=2;i<=MAX;i++){

        if(phi[i]==i){

            for(int j=i;j<=MAX;j+=i){

                phi[j] = phi[j]/i*(i-1);
            }
        }
    }

    for(int i=0;i<=MAX;i++)ans[i] = 1e9;

    phi[1] = 0;
    ans[0] = 1;

    for(int i=1;i<=MAX;i++){

        if(ans[phi[i]]==1e9)ans[phi[i]] = i;
    }

    for(int i=MAX-1;i>=1;i--){

        ans[i] = min(ans[i] , ans[i+1]);
    }
}

int main(void)
{
    seive();

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        ll counter = 0;
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            counter+=ans[in];
        }

        printf("Case %d: %lld Xukha\n",++c , counter);
    }

    return 0;
}
