// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , a , b , c ,d;
        scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
        int tot = (n+2)/2;
        if(tot<=a+b+c+d)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
