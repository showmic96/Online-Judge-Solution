// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        string ar;
        bool check = false;
        cin >> n >> ar;
        for(int i=0;i<ar.size();i++){
            if(ar[i]=='8'){
                if(ar.size()-i>10)check = true;
                break;
            }
        }
        if(check)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
