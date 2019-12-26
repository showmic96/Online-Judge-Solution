// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    int Z[n][2];

    for (int i = 0; i < n; i++)
        Z[i][0] = Z[i][1] = 1;

    int mx = 1;

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {

            if (v[j] < v[i] && Z[i][0] < Z[j][1] + 1)
                Z[i][0] = Z[j][1] + 1;

            if( v[j] > v[i] && Z[i][1] < Z[j][0] + 1)
                Z[i][1] = Z[j][0] + 1;
        }


        if (mx < max(Z[i][0], Z[i][1]))
            mx = max(Z[i][0], Z[i][1]);
    }

    cout << mx << endl;

    return 0;
}
