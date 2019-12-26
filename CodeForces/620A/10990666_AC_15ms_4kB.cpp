#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int px , py , qx , qy;

    cin >> px >> py >> qx >> qy;

    cout << max(abs(px-qx),abs(py-qy)) << endl;

    return 0;
}