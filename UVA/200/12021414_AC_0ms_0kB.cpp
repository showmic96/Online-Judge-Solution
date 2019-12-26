// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar;

    vector<string>v;

    while(getline(cin , ar)){

        if(ar=="#")break;

        v.push_back(ar);
    }

    string ans = "";

    int have[26];
    memset(have , 0 , sizeof(have));

    for(int i=0;i<=20;i++){

        int si = v.size();
        vector<char>temp;

        for(int j=0;j<si;j++){

            if(v[j].size()<i)continue;
            temp.push_back(v[j][i]);
        }

        si = temp.size();
        for(int j=0;j<si;j++){

            if(have[temp[j]-'A']==0){

                ans+=temp[j];
                have[temp[j]-'A'] = 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
