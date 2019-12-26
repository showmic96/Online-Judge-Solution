// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int a, b , c , d;
        scanf("%d %d %d %d",&a , &b , &c , &d);
        if(a+c>b+d)printf("1\n");
        else if(a+c<b+d)printf("2\n");
        else {

            if(b>c)printf("2\n");
            else if(c>b)printf("1\n");
            else printf("-1\n");
        }
    }
    return 0;
}
