#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    string ar;
    getline(cin , ar);
    char br[6];
    br[0]='h';br[1]='e';br[2]='l';br[3]='l';br[4]='o';
    ll c=0;
    for(ll b=0;b<ar.size();b++)if(ar[b]==br[c])c++;
    if(c==5)cout << "YES" << endl;
    else cout << "NO"<< endl;
    return 0;



}
