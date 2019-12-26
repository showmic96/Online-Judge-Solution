// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar;

    while(getline(cin , ar)){

        if(ar[0]=='*')break;
        char x = ar[0];

        stringstream ss (ar);
        string br;
        bool check = true;

        while(ss >> br){

            if(br[0]==x||br[0]+32==x||br[0]-32==x){

            }

            else check = false;
        }

        if(check)cout << "Y" << endl;
        else cout << "N" << endl;
    }

    return 0;
}
