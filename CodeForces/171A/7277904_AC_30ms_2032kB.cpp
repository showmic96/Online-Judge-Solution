#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;

int main(void)
{
    string ar , br , cr;

    cin >> ar >> br;

    cr = "";

    int si = br.size();

    for(int i=si-1;i>=0;i--){

        cr+=br[i];
    }

    stringstream ss(ar);

    ll a, b;

    ss >> a;

    stringstream s(cr);
    s>> b;

    cout << a+b << endl;


    return 0;
}
