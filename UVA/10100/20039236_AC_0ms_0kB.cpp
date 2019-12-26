// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<string>v1 , v2;
int dp[1005][1005];

int f(int i , int j)
{
    if(i==v1.size())return 0;
    if(j==v2.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int value = 0;
    value = max(value , f(i+1 , j));
    value = max(value , f(i , j+1));
    if(v1[i]==v2[j])value = max(value , f(i+1 , j+1)+1);
    return dp[i][j] = value;
}

int main(void)
{
    int c = 0;
    string ar , br;
    while(getline(cin , ar)){
        getline(cin , br);
        for(int i=0;i<ar.size();i++){
            if(isalnum(ar[i]))continue;
            else ar[i] = ' ';
        }
        for(int i=0;i<br.size();i++){
            if(isalnum(br[i]))continue;
            else br[i] = ' ';
        }
        v1.clear();v2.clear();
        stringstream s(ar);
        stringstream ss(br);
        string temp;
        while(s >> temp)v1.push_back(temp);
        while(ss >> temp)v2.push_back(temp);
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                dp[i][j] = -1;
            }
        }
        int ans = f(0 , 0);
        if(ans==0)printf("%2d. Blank!\n",++c);
        else printf("%2d. Length of longest match: %d\n",++c , ans);
    }
    return 0;
}
