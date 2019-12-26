// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , now = 0 , mi = 1e9;
    string ar;
    cin >> n >> ar;
    for(int i=0;i<n;i++){
        if(ar[i]=='(')now++;
        else now--;
        mi = min(mi , now);
    }
    if(now==0&&mi>=-1)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
