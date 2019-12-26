// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    map<char, int>maping;
    string ar;
    cin >> ar;

    int si = ar.size();
    int d = 0;

    for(int i=0;i<si;i++){

        d = i;

        while(ar[i]==ar[d]){d++;if(d==si)break;}
        cout << ar[i] << d-i;
        i = d-1;
    }
    cout << endl;
    return 0;
}
