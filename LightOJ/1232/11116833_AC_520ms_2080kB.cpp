// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;
int MOD = 100000007;
int way[MAX+9];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(way , 0 , sizeof(way));

        int n , k;

        scanf("%d %d",&n , &k);

        vector<int>v;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        way[0] = 1;

        for(int j=0;j<n;j++){

            for(int i=1;i<=k;i++){

                if(i>=v[j]){

                    way[i]+=way[i-v[j]];
                    way[i]%=MOD;
                }
            }
        }

        printf("Case %d: %d\n",++c , way[k]);
    }

    return 0;
}
