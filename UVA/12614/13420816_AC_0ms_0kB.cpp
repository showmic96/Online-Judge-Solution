// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , mx = 0;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            mx = max(mx , in);
        }

        printf("Case %d: %d\n",++c , mx);
    }

    return 0;
}
