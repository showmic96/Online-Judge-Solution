// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{

    int t, c = 0;
    scanf("%d",&t);
    while(t--){

        ll n;
        scanf("%lld",&n);
        char ar[11];

        scanf("%s",&ar);

        if(ar[0]=='A'){

            if(n%3==2||n%3==0)printf("Case %d: Alice\n",++c);
            else printf("Case %d: Bob\n",++c);
        }

        else{

            if(n%3==0)printf("Case %d: Alice\n",++c);
            else printf("Case %d: Bob\n",++c);
        }
    }
    return 0;
}
