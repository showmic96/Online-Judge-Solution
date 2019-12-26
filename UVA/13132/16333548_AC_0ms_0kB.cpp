// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int phi[100005] , mark[100005];

void sievephi()
{
    int i , j , n = 100000;

    for(i=1;i<=n;i++)phi[i] = i;

    phi[1] = 1;
    mark[1] = 1;

    for(i=2;i<=n;i++){

        if(!mark[i]){

            for(j=i;j<=n;j+=i){

                mark[j] = 1;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main(void)
{
    sievephi();
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }
    return 0;
}
