// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//char ar[2005];
//char br[2005];
int lcs[2005][2005];

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        string ar , br;
        cin >> ar >> br;

        int si1 = ar.size();
        int si2 = br.size();

        for(int i=0;i<=si1;i++)lcs[i][0] = i;
        for(int i=0;i<=si2;i++)lcs[0][i] = i;


        for(int i=1;i<=si1;i++){

            for(int j=1;j<=si2;j++){

                if(ar[i-1]==br[j-1]){

                    lcs[i][j] = min(lcs[i-1][j-1] , min(lcs[i-1][j]+1 , lcs[i][j-1]+1));
                }

                else{

                    lcs[i][j] = min(lcs[i-1][j-1] , min(lcs[i-1][j] , lcs[i][j-1]))+1;
                }
            }
        }

        ll ans = lcs[si1][si2];

        printf("%lld\n",ans);
    }
    return 0;
}
