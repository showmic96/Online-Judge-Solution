// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{

    int t , c = 0;
    cin >> t;

    while(t--){

        string ar;
        cin >> ar;

        int si = ar.size();

        int fr[26];

        memset(fr , 0 , sizeof(fr));

        for(int i=0;i<si;i++){

            fr[ar[i]-'a']++;
        }

        int ans = 1e7;

        for(int i=0;i<26;i++){

            ans = min(fr[i] , ans);
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
