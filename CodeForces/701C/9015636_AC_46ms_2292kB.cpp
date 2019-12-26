// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    string ar;
    cin >> n >> ar;

    int p1 = 0 , p2 = 0 , need = 0 , counter = 1 , ans = INT_MAX;
    map<char,int>mp;

    for(int i=0;i<n;i++){

        if(mp[ar[i]]==0){

            need++;
            mp[ar[i]] = 1;
        }
    }

    mp.clear();
    mp[ar[p1]] = 1;

    while(p2!=n){

        if(counter<need){

            //cout << ar[p2] << endl;
            p2++;

            if(mp[ar[p2]]==0){

                counter++;
            }

            mp[ar[p2]]++;
            //p2++;
        }

        else{

            //cout << need << " " << counter << " " << p1 << " " << p2 << endl;

            ans = min(ans , p2-p1);

            mp[ar[p1]]--;
            if(mp[ar[p1]]==0)counter--;
            p1++;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}
