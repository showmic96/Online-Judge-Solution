// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char x[55];
map<string , int>mp;
map<string , int>mp2;

bool cmp(string ar , string br)
{
    return mp2[ar]<mp2[br];
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        mp.clear();

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            scanf("%s",&x);
            string ar(x);
            mp[ar] = 1;
            mp2[ar] = i;
        }

        scanf("%s",&x);
        string now(x);

        vector<string>ans;

        for(int i=0;i<now.size();i++){

            string temp = now;

            for(int j=0;j<=9;j++){

                temp = now;
                temp[i] = '0'+j;
                if(temp==now)continue;
                if(mp.find(temp)!=mp.end())ans.push_back(temp);
            }
        }

        if(mp.find(now)!=mp.end())ans.push_back(now);
        sort(ans.begin() , ans.end() , cmp);
        printf("Case %d:\n",++c);
        for(int i=0;i<ans.size();i++){

            for(int j=0;j<ans[i].size();j++)printf("%c",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
