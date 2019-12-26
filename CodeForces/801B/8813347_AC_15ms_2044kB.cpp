// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{

    string ar , br;
    cin >> ar >> br;
    bool check = true;
    
    for(int i=0;i<ar.size();i++){
        
        if(ar[i]<br[i])check=false;
    }
    if(check==false)cout << -1 << endl;
    else cout << br << endl;
    return 0;
}
