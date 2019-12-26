// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans[] = {1 , 1 , 3 , 13 , 75 , 541 , 4683 , 47293,
    545835 , 7087261 , 102247563 , 1622632573};
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
