// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    cin.ignore();
    while(t--){

        string ar , br;
        getline(cin , ar);

        stringstream ss(ar);
        map<string , string>mp;

        while(ss >> br){

            string temp = br;

            if(temp.size()>2)sort(temp.begin()+1 , temp.begin()+temp.size()-1);
            if(mp.find(temp)==mp.end())mp[temp] = br;
            else {

                mp[temp] = min(mp[temp] , br);
            }
        }

        getline(cin , ar);

        stringstream st(ar);
        bool found = false;

        while(st >> br){

            if(found==true)cout << " ";
            found = true;

            string temp = br;

            if(temp.size()>2)sort(temp.begin()+1 , temp.begin()+temp.size()-1);
            if(mp.find(temp)!=mp.end())cout << mp[temp];
            else {

                cout << br;
            }
        }
        cout << endl;
    }

    return 0;
}
