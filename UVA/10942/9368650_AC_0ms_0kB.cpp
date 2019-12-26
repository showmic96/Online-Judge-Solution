// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1234567891011121314;

ll y , m , d;

bool leap_year(ll x)
{
    if(x%400==0)return true;
    if(x%100==0)return false;
    if(x%4==0)return true;
}

void find_out(ll x , ll yt , ll mt , ll dt)
{
    ll t = yt;
    x*=10;
    if(yt==0)x*=10;

    while(yt!=0){

        x*=10;
        x+=yt%10;
        yt/=10;
    }

    yt = t;

    if(dt>31)return ;
    if(mt>12)return ;

    if(dt<=0||mt<=0)return ;

    if(mt==1||mt==3||mt==5||mt==7||mt==8||mt==10||mt==12){

    }

    else if(mt==2){

        if(leap_year(x)==true){

            if(dt>29)return ;
        }
        else{

            if(dt>28)return ;
        }
    }

    else{

        if(dt==31)return;
    }

    if(yt<y){

        y = yt;
        m = mt;
        d = dt;
    }

    else if(yt==y){

        if(mt<m){

            m = mt;
            d = dt;
        }
    }

    return ;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll year , a , b , c;
        y = INF;
        m = INF;
        d = INF;

        scanf("%lld %lld %lld %lld",&year , &a , &b , &c);

        find_out(year , a , b , c);
        find_out(year , b , a , c);
        find_out(year , b , c , a);
        find_out(year , c , b , a);
        find_out(year , c , a , b);
        find_out(year , a , c , b);

        if(y==INF)printf("-1\n");
        else{

            if(y<10)printf("0%d",y);
            else printf("%d",y);

            if(m<10)printf(" 0%d",m);
            else printf(" %d",m);

            if(d<10)printf(" 0%d\n",d);
            else printf(" %d\n",d);
        }
    }
    return 0;
}
