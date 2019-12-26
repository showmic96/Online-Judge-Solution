// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<string>v1 , v2;
        set<string>st1 , st2;

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;
            v1.push_back(ar);
        }

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;
            v2.push_back(ar);
        }

        bool check = false;

        for(int i=0;i<n;i++){

            st1.insert(v1[i]);
            st2.insert(v2[i]);

            if(st1==st2){

                if(check)cout << " ";
                check = true;
                cout << st1.size();

                st1.clear();
                st2.clear();
            }
        }

        cout << endl;
    }

    return 0;
}
