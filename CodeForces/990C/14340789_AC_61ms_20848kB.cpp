// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int lft[300005] , rgt[300005] , ok = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    memset(lft , 0 , sizeof(lft));
    memset(rgt , 0 , sizeof(rgt));

    vector<string>v;

    for(int i=0;i<n;i++){

        string ar;
        cin >> ar;

        int l = 0 , r = 0;

        for(int j=0;j<ar.size();j++){

            if(ar[j]==')'){

                if(r>0)r--;
                else l++;
            }
            else{

                r++;
            }
        }

        if(l==0&&r==0)ok++;
        else if(l>0&&r>0)continue;
        else if(l>0)lft[l]++;
        else rgt[r]++;

        v.push_back(ar);
    }

    ll ans = 0;

    for(int i=0;i<v.size();i++){

        string ar = v[i];

        int l = 0 , r = 0;

        for(int j=0;j<ar.size();j++){

            if(ar[j]==')'){

                if(r>0)r--;
                else l++;
            }
            else{

                r++;
            }
        }

        if(l==0&&r==0)ans+=ok;
        else if(l>0)ans+=rgt[l];
    }

    cout << ans << endl;

    return 0;
}
