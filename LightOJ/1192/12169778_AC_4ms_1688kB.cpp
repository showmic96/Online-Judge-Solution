// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;

    scanf("%d",&t);
    while(t--){

        int k;
        scanf("%d",&k);

        int t1 = 0 , t2 = 0 , sum = 0;

        for(int i=0;i<k;i++){

            scanf("%d %d",&t1,&t2);

            t1 = (t2-t1-1);
            sum^=t1;
        }

        if(!sum)printf("Case %d: Bob\n",++c);
        else printf("Case %d: Alice\n",++c);
    }

    return 0;
}