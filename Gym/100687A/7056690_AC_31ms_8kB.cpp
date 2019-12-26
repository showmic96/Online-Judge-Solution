#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    string ar;

    cin >> ar;

    bool check = false;

    for(int i=0;i<ar.size();i++){

        if(ar[i]=='?')check = true;
    }

    if(check==false)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
