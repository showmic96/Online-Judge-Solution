// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char to_lower(char x)
{
    if(x>='A'&&x<='Z')return x+32;
    return x;
}

int main(void)
{
    string ar , br;
    vector<string>v;
    vector<string>ans;
    map<string , int>mp;

    while(getline(cin , ar)){

        if(ar=="#")break;
        stringstream ss(ar);

        while(ss >> br){

            string temp = br;
            //sort(temp.begin() , temp.end());
            int si = temp.size();

            for(int i=0;i<si;i++){

                temp[i] = to_lower(temp[i]);
            }
            sort(temp.begin() , temp.end());
            //cout << temp << endl;
            mp[temp]++;
            v.push_back(br);
        }
    }

    int si = v.size();

    for(int i=0;i<si;i++){

        string temp = v[i];
        //sort(temp.begin() , temp.end());
        int s = temp.size();

        for(int j=0;j<s;j++){

            temp[j] = to_lower(temp[j]);
        }

        sort(temp.begin() , temp.end());

        if(mp[temp]==1)ans.push_back(v[i]);
    }

    si = ans.size();
    sort(ans.begin() , ans.end());
    for(int i=0;i<si;i++){
        cout << ans[i] << endl;
    }

    return 0;
}
