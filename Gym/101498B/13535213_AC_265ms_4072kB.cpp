// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        map<char , int>mp;

        string ar , br;
        cin >> ar >> br;

        int mx = 0;

        for(int i=0;i<br.size();i++)mp[br[i]]++;
        for(int i=0;i<ar.size();i++){

            if(mp[ar[i]]>0){

                mx++;
                mp[ar[i]]--;
            }

            else break;
        }

        cout << mx << endl;
    }
    return 0;
}
