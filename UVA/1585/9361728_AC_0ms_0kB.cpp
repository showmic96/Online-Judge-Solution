// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        string ar;
        cin >> ar;

        int si = ar.size();
        long long ans = 0 , d = 0;

        for(int i=0;i<si;i++){

            if(ar[i]=='X')d = 0;
            else d++;
            ans+=d;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
