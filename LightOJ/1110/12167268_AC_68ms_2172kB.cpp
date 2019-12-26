// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char in1[105] , in2[105];
string ans[105][105];
string cmp(string x , string y)
{
    if(x.size()==y.size()){

        if(x<y)return x;
        return y;
    }

    if(x.size()>y.size())return x;
    return y;
}

int main(void)
{
    int t , c = 0;

    scanf("%d",&t);
    while(t--){

        scanf("%s %s",&in1 , &in2);
        string ar(in1 , strlen(in1));
        string br(in2 , strlen(in2));

        int n = ar.size() , m = br.size();

        for(int i=0;i<=n;i++){

            for(int j=0;j<=m;j++){

                ans[i][j] = "";
            }
        }

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(ar[i-1]==br[j-1]){

                    ans[i][j] = cmp(ans[i][j] , ans[i-1][j-1]+ar[i-1]);
                }

                else{

                    ans[i][j] = cmp(ans[i][j] , cmp(ans[i-1][j] , ans[i][j-1]));
                }
            }
        }

        if(ans[n][m]=="")printf("Case %d: :(\n",++c);
        else {

            printf("Case %d: ",++c);

            int si = ans[n][m].size();

            for(int i=0;i<si;i++){

                printf("%c",ans[n][m][i]);
            }

            printf("\n");
        }
    }

    return 0;
}
