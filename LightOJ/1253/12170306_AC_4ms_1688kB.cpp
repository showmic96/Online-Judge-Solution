// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d", &n);

        int counter = 0 , ans = 0;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            if(in==1)counter++;
            ans^=in;
        }

        if(counter==n){

            if(!(n&1))printf("Case %d: Alice\n",++c);
            else printf("Case %d: Bob\n",++c);
        }
        else{

            if(ans)printf("Case %d: Alice\n",++c);
            else printf("Case %d: Bob\n",++c);
        }
    }
    return 0;
}
