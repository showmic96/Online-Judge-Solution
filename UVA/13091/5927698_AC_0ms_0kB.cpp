#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b , c , d ,e , f, g,h,i,j;char x;
    cin >> a;
    for(b=0;b<a;b++){j=0;
        for(c=0;c<5;c++){if(!j){e=0;f=0;g=0;h=0;}
            for(d=0;d<5;d++){cin >> x;
                if(j==0){
                if(!e&&!h){if(x=='<')e=1;if(x=='>')e=2;}
                if(e==1&&x=='|'){g=1;j=1;}
                if(e==2&&x=='|'){g=2;j=1;}
                if(!e&&x=='|')h=1;
                if(h==1){if(x=='<'){g=2;j=1;}if(x=='>'){g=1;j=1;}}}
            }
           // if(g==1||g==2)break;
        }
       // cout << endl;
        if(g==1)printf("Case %lld: No Ball\n",b+1);
        if(g==2)printf("Case %lld: Thik Ball\n",b+1);
        //cout << endl;
    }
    return 0;
}
