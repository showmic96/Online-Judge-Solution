#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    string ar;
    getline(cin ,ar);
    int a=ar.size();
    cout << (a)*26+(26-a) << endl;

    return 0;
}
