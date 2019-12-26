// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a , b , c;
    while(scanf("%d %d %d",&a , &b , &c)==3){

        if(!a&&!b&&!c)break;
        if(b-a==c-b)printf("AP %d\n",c+c-b);
        else printf("GP %d\n",c*(c/b));
    }
    return 0;
}
