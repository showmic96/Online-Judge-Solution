// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int g(int n)
{
    if(n==0)return 1;
    if(n==1)return 0;

    if(n%2==0)return n/2;
    return g((int)(n/2));
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        int ans = 0;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            ans^=g(in);
        }

        if(ans)printf("Case %d: Alice\n",++c);
        else printf("Case %d: Bob\n",++c);
    }
    return 0;
}
