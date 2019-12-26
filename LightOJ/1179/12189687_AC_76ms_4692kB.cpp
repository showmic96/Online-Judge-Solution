// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int f(int n , int k)
{
    if(n==1)return 1;

    return (f(n-1 , k)+k-1)%n+1;
}
int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , k;
        scanf("%d %d",&n , &k);
        printf("Case %d: %d\n",++c , f(n , k));
    }
    return 0;
}
