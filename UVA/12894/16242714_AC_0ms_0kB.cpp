// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 , cx , cy , r , t;

    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d %d %d %d %d",&x1 , &y1 , &x3 , &y3 , &cx , &cy , &r);

        x4 = x1;y4 = y3;
        x2 = x3;y2 = y1;

        bool check = true;

        int t1 = (x2-x1)*9;

        if(t1%20)check = false;
        t1/=20;
        t1+=x1;

        int t2 = (y4-y1);
        if(t2%2)check = false;
        t2/=2;
        t2+=y1;

        if(t1!=cx)check = false;
        if(t2!=cy)check = false;

        int h = (y4-y1);
        int w = (x2-x1);

        if(h*10!=w*6)check = false;
        if(r*5!=w)check = false;

        if(check)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
