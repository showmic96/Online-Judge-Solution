// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 50001+9;

int phi[MAX+9] , mark[MAX+9];
void sievephi()
{
    int i , j;
    for(int i=1;i<=MAX;i++)phi[i] = i;

    phi[1] = 1;
    mark[1] = 1;

    for(int i=2;i<=MAX;i++){

        if(!mark[i]){

            for(int j=i;j<=MAX;j+=i){

                mark[j] = 1;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main(void)
{
    sievephi();
    for(int i=2;i<=MAX;i++)phi[i] = phi[i-1] + phi[i]*2;

    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;
        printf("%d\n",phi[n]);
    }

    return 0;
}
