// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool all(string ar)
{
    for(int i=0;i<ar.size();i++)if(ar[i]!='1')return false;
    return true;
}

ll get(string ar , ll b)
{
    ll now = 0;
    for(int i=0;i<ar.size();i++){

        now*=b;
        now+=ar[i]-'0';
    }
    return now;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        string ar , br , cr , temp;
        cin >> ar >> temp >> br;
        cin >> temp >> cr;

        int ans = 0;

        if(all(ar)==true&&all(br)==true&&all(cr)==true){

            if(ar.size()+br.size()==cr.size()){cout << 1 << endl;continue;}
        }

        int mi = 1;
        for(int i=0;i<ar.size();i++)mi = max((int)(ar[i]-'0') , mi);
        for(int i=0;i<br.size();i++)mi = max((int)(br[i]-'0') , mi);
        for(int i=0;i<cr.size();i++)mi = max((int)(cr[i]-'0') , mi);

        for(int i=mi+1;i<=26;i++){

            if(get(ar , i)+get(br , i)==get(cr , i)){

                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
