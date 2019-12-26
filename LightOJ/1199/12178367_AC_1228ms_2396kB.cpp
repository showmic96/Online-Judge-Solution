// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int g[MAX+9];

int f(int i)
{
    if(i==1||i==2)return 0;

    if(g[i]!=-1)return g[i];

    map<int , int>mp;
    bool check = false;

    for(int j=1;j<=i;j++){

        if(j>=i-j)break;
        int temp = f(j)^f(i-j);
        if(temp==0)check = true;
        mp[temp] = 1;
    }

    if(check==false)return g[i]=0;

    for(int j=1;;j++){

        if(mp[j]==1)continue;

        g[i] = j;
        break;

    }

    return g[i];
}

int main(void)
{
    memset(g , -1 , sizeof(g));

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        vector<int>v;
        int ans = 0;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            ans^=f(in);
        }

        if(ans)printf("Case %d: Alice\n",++c);
        else printf("Case %d: Bob\n",++c);
    }
    return 0;
}
