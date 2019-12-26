// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 50000+9;
vector<int>v[MAX+9];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        //for(int i=0;i<=n;i++)v[i].clear();

        int ans = 0;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                int in;
                scanf("%d",&in);

                if((n-i+m-j)%2==1)ans^=in;
            }
        }

        if(ans)printf("Case %d: win\n",++c);
        else printf("Case %d: lose\n",++c);
    }
    return 0;
}