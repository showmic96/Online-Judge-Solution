// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int mp[100005];
int ar[100005];

int main(void)
{
    int n , m;
    while(scanf("%d %d",&m , &n)==2){

        for(int i=0;i<=n;i++)mp[i] = 0;

        mp[0] = 1;
        ar[0] = 0;

        bool check = true;

        for(int i=1;i<n;i++){

            ar[i] = (ar[i-1]+m)%n;
            mp[ar[i]]++;

            if(mp[ar[i]]>1)check = false;
        }

        if(check)printf("%10d%10d    Good Choice\n\n",m,n);
        else printf("%10d%10d    Bad Choice\n\n",m,n);
    }
    return 0;
}
