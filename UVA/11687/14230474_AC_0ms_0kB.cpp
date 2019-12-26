// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar;

    while(cin >> ar){

        if(ar=="END")break;
        if(ar=="1"){
            
            cout << 1 << endl;
            continue;
        }

        int counter = 1 , now = ar.size();

        while(now>1){

            counter++;

            now = floor(log10(now)) + 1;
        }

        cout << counter+1 << endl;
    }

    return 0;
}
