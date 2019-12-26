// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char s[100005];
int lvl[100005] , par[100005];
map<string ,int>mp;
map<int , string>ump;

int main(void)
{
    string ar;
    int c = 1;
    vector<string>v;
    while(gets(s)){
        if(s[0]=='7')break;
        ar = "";
        for(int i=0;i<strlen(s);i++)ar+=s[i];
        if(ar=="")break;
        v.push_back(ar);
        mp[ar] = c;
        ump[c] = ar;
        c++;
    }
    string s1 , s2;
    bool blank = false;
    while(cin >> s1 >> s2){
        if(blank)cout << endl;
        else blank = true;
        for(int i=0;i<=c;i++)lvl[i] = 1e9 , par[i] = -1;
        queue<int>current;
        current.push(mp[s1]);
        lvl[mp[s1]] = 0;
        while(!current.empty()){
            int u = current.front();
            current.pop();
            string now = ump[u];
            for(int i=0;i<now.size();i++){
                for(int j=0;j<26;j++){
                    if(now[i]-'a'==j)continue;
                    string temp = "";
                    for(int k=0;k<now.size();k++){
                        if(k==i)temp+=j+'a';
                        else temp+=now[k];
                    }
                    if(mp.find(temp)!=mp.end()&&lvl[mp[temp]]>lvl[u]+1){
                        current.push(mp[temp]);
                        par[mp[temp]] = u;
                        lvl[mp[temp]] = lvl[u]+1;
                    }
                }
            }
        }
        vector<int>ans;
        ans.push_back(mp[s2]);
        int t = par[mp[s2]];
        while(t!=-1){
            ans.push_back(t);
            t = par[t];
        }
        reverse(ans.begin() , ans.end());
        if(ans.size()<=1)cout << "No solution." << endl;
        else{
            for(int i=0;i<ans.size();i++){
                cout << ump[ans[i]] << endl;
            }
        }
    }
    return 0;
}
