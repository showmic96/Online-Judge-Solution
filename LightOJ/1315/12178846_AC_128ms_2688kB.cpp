// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int g[505][505];

int f(int i , int j)
{
    if(i<0||j<0)return 12345678;
    if(i>500||j>500)return 12345678;

    if(g[i][j]!=-1)return g[i][j];

    map<int , int>mp;

    mp[f(i-2 , j+1)] = 1;
    mp[f(i-3 , j-1)] = 1;
    mp[f(i-2 , j-1)] = 1;
    mp[f(i-1 , j-2)] = 1;
    mp[f(i-1 , j-3)] = 1;
    mp[f(i+1 , j-2)] = 1;

    for(int i1=0;;i1++){
        if(mp[i1]==0){

            g[i][j] = i1;
            break;
        }
    }

    return g[i][j];
}

int main(void)
{
    memset(g , -1 , sizeof(g));

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        int ans = 0;

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            ans^=f(in1 , in2);
        }

        if(ans)printf("Case %d: Alice\n",++c);
        else printf("Case %d: Bob\n",++c);
    }
    return 0;
}
