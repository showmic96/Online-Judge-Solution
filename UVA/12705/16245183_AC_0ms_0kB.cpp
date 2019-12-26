// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
char ar[105];

int main(void)
{
    for(int i=1;i<=6;i++){

        for(int j=1;j<=6;j++)v.push_back(i+j);
    }

    sort(v.begin() , v.end());

    int t;
    scanf("%d",&t);
    getchar();
    while(t--){

        gets(ar);
        map<char , int>mp;

        for(int i=0;i<strlen(ar);i++){

            if(ar[i]!=' ')mp[ar[i]]++;
        }

        vector<int>temp;

        for(auto it = mp.begin();it!=mp.end();it++){

            temp.push_back(it->second);
        }

        sort(temp.begin(),temp.end());

        ll ans = 0 , c = 0;

        for(int i=temp.size()-1;i>=0;i--){

            ans+=v[c]*temp[i];
            c++;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
