// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int lis[2005] , lds[2005];

vector<int>v;
int n;

int f1(int i)
{

    if(lis[i]!=-1)return lis[i];
    int mx = 0;
    for(int j=i;j<n;j++){

        if(v[j]<v[i])mx = max(mx , f1(j));
    }

    return lis[i] = mx+1;
}

int f2(int i)
{

    if(lds[i]!=-1)return lds[i];
    int mx = 0;
    for(int j=i;j<n;j++){

        if(v[j]>v[i])mx = max(mx , f2(j));
    }

    return lds[i] = mx+1;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        memset(lis , -1 , sizeof(lis));
        memset(lds , -1 , sizeof(lds));

        lis[n] = 1;
        lds[n] = 1;

        int mx = 0;

        for(int i=0;i<n;i++){

            mx = max(mx , f1(i)+f2(i)-1);
        }

        printf("%d\n",mx);
    }
    return 0;
}
