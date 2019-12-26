// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , x , y , d;
        scanf("%d %d %d %d",&n , &x , &y , &d);
        int ans = 3e9;

        if(abs(x-y)%d==0)ans = min(ans , abs(x-y)/d);
        //cout << "First Check " << ans << endl;
        if((y-1)%d==0)ans = min(ans , (x-1+d-1)/d + (y-1)/d);
        //cout << "Second Check " << ans << endl;
        if((n-y)%d==0)ans = min(ans , (n-x+d-1)/d+(n-y)/d);
        //cout << "Third Check " << ans << endl;

        if(ans>2e9)ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}
