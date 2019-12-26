// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    scanf("\n");

    while(t--){

        string ar;
        getline(cin , ar);

        vector<int>v;

        int temp;
        stringstream ss(ar);

        while(ss>>temp){

            v.push_back(temp);
        }

        int si = v.size();
        int mx = 0;

        for(int i=0;i<si;i++){

            for(int j=i+1;j<si;j++){

                mx = max(mx , __gcd(v[i],v[j]));
            }
        }

        cout << mx << endl;
    }
    return 0;
}
