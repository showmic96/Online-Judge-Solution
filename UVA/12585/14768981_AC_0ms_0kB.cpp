// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double f(int a , int b , int l)
{
    if(l>=100)return 0;

    if(a==b)return 1.0;
    if(a>b)return f(a-b , b+b , l+1)*0.5 + 1;
    else return f(a+a , b-a , l+1)*0.5 + 1;
}

double f2(int a , int b , double p)
{
    if(p<0.000000001)return 0;
    if(a>b)return f2(a-b , b+b , p/2) + p/2*1;
    return f2(a+a , b-a , p/2);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int a, b;
        scanf("%d %d",&a , &b);
        printf("Case %d: %.6f %.6f\n",++c , f(a , b , 0) , f2(a , b , 1));
    }

    return 0;
}
