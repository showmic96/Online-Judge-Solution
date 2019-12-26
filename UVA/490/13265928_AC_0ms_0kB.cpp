// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ans[105];
string store[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<104;i++){

        ans[i] = "";

        for(int j=0;j<104;j++){

            ans[i] += " ";
        }
    }

    int row = 0 , col = 0;

    string ar;

    while(getline(cin , ar)){

        store[row] = ar;
        row++;
    }

    for(int i=0;i<row;i++){

        int si = store[i].size();
        col = max(col , si);

        for(int j=0;j<si;j++){

            ans[j][i] = store[i][j];
        }
    }

    for(int i=0;i<col;i++){
        
        reverse(ans[i].begin() , ans[i].end());
        for(int j=0;j<row;j++)cout << ans[i][104-row+j];
        cout << endl;
    }

    return 0;
}
