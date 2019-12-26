// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar , br;
    while(cin >> ar >> br){
        int fr1[26] , fr2[26];
        memset(fr1 , 0 , sizeof(fr1));
        memset(fr2 , 0 , sizeof(fr2));
        multiset<int>st1 , st2;
        for(int i=0;i<ar.size();i++){
            fr1[ar[i]-'A']++;
            fr2[br[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            st1.insert(fr1[i]);
            st2.insert(fr2[i]);
        }
        if(st1==st2)cout << "YES" << endl;
        else  cout << "NO" << endl;
    }

    return 0;
}
