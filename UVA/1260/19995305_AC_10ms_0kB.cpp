// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int>v(n);
        for(auto &x:v)scanf("%d",&x);
        int ans = 0;
        for(int i=1;i<n;i++){
            int sum = 0;
            for(int j=0;j<i;j++){
                if(v[i]>=v[j])sum++;
            }
            ans+=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
