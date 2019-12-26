// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10010;
int h[MAX] , w[MAX] , dp1[MAX] , dp2[MAX];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&h[i]);
        for(int i=0;i<n;i++){
            scanf("%d",&w[i]);
            dp1[i] = dp2[i] = w[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(h[i]<h[j]&&dp1[i]+w[j]>dp1[j]){
                    dp1[j] = dp1[i]+w[j];
                }
                if(h[i]>h[j]&&dp2[i]+w[j]>dp2[j]){
                    dp2[j] = dp2[i]+w[j];
                }
            }
        }
        int ans1 = 0 , ans2 = 0;
        for(int i=0;i<n;i++){
            ans1 = max(ans1 , dp1[i]);
            ans2 = max(ans2 , dp2[i]);
        }
        if(ans1>=ans2){
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",++c , ans1 , ans2);
        }
        else{
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",++c , ans2 , ans1);
        }
    }
    return 0;
}
