// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        string ar , br;
        getline(cin , ar);
        getline(cin , br);
        cout << "Case " << ++c << ": ";
        if(ar==br)cout << "Yes" << endl;
        else{
            string t1 = "" , t2 = "";
            for(int i=0;i<ar.size();i++){
                if(ar[i]!=' ')t1+=ar[i];
            }
            for(int i=0;i<br.size();i++){
                if(br[i]!=' ')t2+=br[i];
            }
            if(t1==t2)cout << "Output Format Error" << endl;
            else cout << "Wrong Answer" << endl;
        }
    }

    return 0;
}
