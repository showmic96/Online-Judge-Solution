// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

map<long long , long long>mp[26];
string ar;
long long fr[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<26;i++)cin >> fr[i];

    cin >> ar;

    long long ans = 0 , sum = 0;

    for(int i=0;i<ar.size();i++){

        int now = ar[i] - 'a';
        ans+=mp[now][sum];
        sum+=fr[now];
        mp[now][sum]++;
    }

    cout << ans << endl;

    return 0;
}
