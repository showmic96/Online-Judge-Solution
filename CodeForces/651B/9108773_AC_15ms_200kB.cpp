// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int d = 0 , mx = 0 , in;
    set<int>s[1234];
    set<int>::iterator it;

    for(int i=0;i<n;i++){

        cin >> in;

        for(int j=0;j<=mx+1;j++){

            it = s[j].find(in);

            if(it==s[j].end()){

                //cout << "YES" << endl;
                s[j].insert(in);
                mx = max(mx , j);
                break;
            }
            mx = max(mx , j);
        }
    }

    int sum = 0;

    for(int i=0;i<=mx;i++){

        sum+=(s[i].size() - 1);
    }

    cout << sum << endl;

    return 0;
}
