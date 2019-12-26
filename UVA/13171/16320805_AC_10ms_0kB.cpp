// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[100005];
int a , b , c;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d %s",&a , &b , &c , &ar);

        for(int i=0;i<strlen(ar);i++){

            if(ar[i]=='M')a--;
            else if(ar[i]=='Y')b--;
            else if(ar[i]=='C')c--;
            else if(ar[i]=='R')a--,b--;
            else if(ar[i]=='V')a--,c--;
            else if(ar[i]=='G')b--,c--;
            else if(ar[i]=='B')a--,b--,c--;
        }

        if(a<0||b<0||c<0)printf("NO\n");
        else printf("YES %d %d %d\n",a , b , c);
    }
    return 0;
}
