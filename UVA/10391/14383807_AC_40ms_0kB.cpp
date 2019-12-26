// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string>v , ans;
map<string , int>mp;

bool cmp(string A , string B)
{
    if(A.size()==B.size())return A<B;
    return A.size()<B.size();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar;
    while(cin >> ar)v.push_back(ar);

    sort(v.begin() , v.end() , cmp);

    for(int i=0;i<v.size();i++){

        string temp = "";
        bool check = false;
        for(int j=0;j<v[i].size();j++){

            temp+=v[i][j];
            if(mp.find(temp)!=mp.end()){

                string now = "";
                for(int k=j+1;k<v[i].size();k++)now+=v[i][k];
                if(mp.find(now)!=mp.end()){

                    check = true;
                    break;
                }
            }
        }
        if(check==true)ans.push_back(v[i]);
        mp[v[i]] = 1;
    }
    sort(ans.begin() , ans.end());
    for(int i=0;i<ans.size();i++)cout << ans[i] << endl;

    return 0;
}
