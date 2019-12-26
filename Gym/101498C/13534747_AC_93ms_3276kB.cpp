// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int ar[3] , a , b, c;
        scanf("%d %d %d",&a , &b , &c);
        ar[0] = a;
        ar[1] = b;
        ar[2] = c;

        sort(ar , ar+3);

        if(a==ar[0])printf("First\n");
        else if(b==ar[0])printf("Second\n");
        else printf("Third\n");
    }
    return 0;
}
