// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , x;
    scanf("%d %d",&n , &x);

    vector<int>v;
    map<int , int>mp1 , mp2;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);

        int temp = in&x;
        v.push_back(in);

        mp1[in]++;
        mp2[temp]++;

    }

    int ans = 1e9;

    for(int i=0;i<n;i++){
        if(mp1[v[i]]>1)ans = min(ans , 0);
        if(mp2[v[i]]>1)ans = min(ans , 1);
        if(mp2[v[i]&x]>1)ans = min(ans , 2);
    }

    if(ans==1e9)ans = -1;
    printf("%d\n",ans);

    return 0;
}
