// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[25][25];
int n;
set<string>ans;

bool valid(int i , int j , char x)
{
    if(i<0||j<0||i>=n||j>=n)return false;
    if(ar[i][j]<=x)return false;
    return true;
}

void dfs(int i , int j , string now)
{
    now+=ar[i][j];
    if(now.size()>2)ans.insert(now);

    if(valid(i+1 , j , ar[i][j])==true)dfs(i+1 , j , now);
    if(valid(i-1 , j , ar[i][j])==true)dfs(i-1 , j , now);
    if(valid(i , j+1 , ar[i][j])==true)dfs(i , j+1 , now);
    if(valid(i , j-1 , ar[i][j])==true)dfs(i , j-1 , now);
    if(valid(i+1 , j+1 , ar[i][j])==true)dfs(i+1 , j+1 , now);
    if(valid(i+1 , j-1 , ar[i][j])==true)dfs(i+1 , j-1 , now);
    if(valid(i-1 , j+1 , ar[i][j])==true)dfs(i-1 , j+1 , now);
    if(valid(i-1 , j-1 , ar[i][j])==true)dfs(i-1 , j-1 , now);
}

bool cmp(string A , string B)
{
    if(A.size()==B.size())return A<B;
    return A.size()<B.size();
}

int main(void)
{
    int t;
    scanf("%d",&t);
    bool space = false;
    while(t--){

        if(space==true)printf("\n");
        space = true;
        ans.clear();

        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%s",&ar[i]);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                dfs(i , j , "");
            }
        }

        vector<string>v;

        for(auto it = ans.begin();it!=ans.end();it++){

            v.push_back(*it);
        }

        sort(v.begin() , v.end() , cmp);

        for(int j=0;j<v.size();j++){

            string now = v[j];

            for(int i=0;i<now.size();i++)printf("%c",now[i]);
            printf("\n");
        }
    }

    return 0;
}
