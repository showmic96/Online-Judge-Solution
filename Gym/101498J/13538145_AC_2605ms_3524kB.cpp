// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while(t--){

        string ar;
        getline(cin , ar);

        bool ans = false;

        for(int i=1;i<ar.size()-2;i++){

            bool check = true;

            for(int j=i;j<ar.size();j+=i){

                if(ar[j]!=' ')check = false;
                j++;
                if(j+i>ar.size())check = false;
            }

            if(check==true)ans = true;
        }

        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
