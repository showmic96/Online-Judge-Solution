// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[1005];
map<string , double>mp;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        mp.clear();

        int n , m;
        scanf("%d %d",&n , &m);

        mp["JD"] = 1;

        for(int i=0;i<n;i++){

            double in;
            scanf("%s %lf",&ar , &in);

            string temp(ar);

            mp[temp] = in;
        }

        double ans = 0;

        for(int i=0;i<m;i++){

            double in;
            scanf("%lf %s",&in , &ar);

            ans+=in*mp[ar];
        }

        printf("%.6f\n",ans);
    }
    return 0;
}
