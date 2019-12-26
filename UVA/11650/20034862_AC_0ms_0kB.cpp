// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int h , m;
        char x;
        scanf("%d:%d",&h , &m);
        m = (60-m)%60;
        h = 12-h;
        if(m!=0)h--;
        h = (h+12)%12;
        if(h==0)h = 12;
        printf("%02d:%02d\n",h , m);
    }

    return 0;
}
