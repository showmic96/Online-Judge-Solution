// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[500005];
int l[500005] , r[500005];
int main(void)
{
    while(scanf("%s",&ar)==1){

        int si = strlen(ar);
        int counter = 1e9;

        for(int i=0;i<si;i++){

            l[i] = r[i] = 0;
        }

        for(int i=0;i<si;i++){

            l[i] = counter;
            if(ar[i]=='X')counter = 0;
            else counter++;
        }

        counter = 1e9;

        for(int i=si-1;i>=0;i--){

            r[i] = counter;
            if(ar[i]=='X')counter = 0;
            else counter++;
        }

        int ans = 0;

        for(int i=0;i<si;i++){

            if(ar[i]=='.')ans = max(ans , min(l[i] , r[i]));
        }

        printf("%d\n",ans);
    }
    return 0;
}
