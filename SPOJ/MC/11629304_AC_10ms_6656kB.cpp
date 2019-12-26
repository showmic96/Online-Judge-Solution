// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[1005];
char br[1005];
int lcs[1005][1005];

int main(void)
{
    while(scanf("%s",&ar)==1){

        if(ar[0]=='#')break;

        scanf("%s",&br);

        int si1 = strlen(ar);
        int si2 = strlen(br);

        memset(lcs, 0 , sizeof(lcs));

        for(int i=1;i<=si1;i++){

            for(int j=1;j<=si2;j++){

                if(ar[i-1]==br[j-1]){

                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }

                else{

                    lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]);
                }
            }
        }

        ll ans = lcs[si1][si2];

        printf("%lld\n",(si1-ans)*15+(si2-ans)*30);
    }
    return 0;
}
