// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double f[10] , r[10];

int main(void)
{
    int n , m;
    while(scanf("%d",&n)==1){

        if(!n)break;
        vector<double>v;

        scanf("%d",&m);

        for(int i=0;i<n;i++)scanf("%lf",&f[i]);
        for(int i=0;i<m;i++)scanf("%lf",&r[i]);

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                v.push_back(r[i]/f[j]);
            }
        }

        sort(v.begin() , v.end());

        double ans = 0;

        for(int i=0;i<v.size()-1;i++){

            ans = max(ans , v[i+1]/v[i]);
        }

        printf("%.2f\n",ans);
    }
    return 0;
}
