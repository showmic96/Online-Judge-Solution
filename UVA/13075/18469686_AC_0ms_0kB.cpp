// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int len;bool space;

int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}

void f(int n , int m , int l , int mask)
{
    if(n==0&&m==0){
        if(space)printf(" ");
        for(int i=0;i<len;i++){

            if(Check(mask , i)==true)printf("V");
            else printf("C");
        }
        space = true;
    }
    if(n>0)f(n-1 , m , l+1,  mask);
    if(m>0)f(n , m-1 , l+1 , Set(mask , l));
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);
        len = n+m;space = false;
        f(n , m , 0 , 0);
        printf("\n");
    }
    return 0;
}
