// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(string A , string B)
{
    return A.size()<B.size();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<string>v;
    string ar;int c = 0;

    while(cin >> ar){

        if(ar=="9"){

            sort(v.begin() , v.end() , cmp);
            map<string , int>mp;
            bool check = true;

            for(int i=0;i<v.size();i++){

                string temp = "";

                for(int j=0;j<v[i].size();j++){

                    temp+=v[i][j];
                    if(mp.find(temp)!=mp.end())check = false;
                }
                mp[temp] = 1;
            }

            if(check==true)cout << "Set " << ++c << " is immediately decodable" << endl;
            else cout << "Set " << ++c << " is not immediately decodable" << endl;
            v.clear();
        }
        else v.push_back(ar);
    }

    return 0;
}
