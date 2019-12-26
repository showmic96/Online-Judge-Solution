// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    while(cin >> s){

        if(s[0]=='0')break;

        memset(ar , 0 , sizeof(ar));
        stringstream ss(s);

        int n;
        ss >> n;

        vector<int>v;

        for(int i=0;i<n;i++){

            int in;
            cin >> in;
            v.push_back(in);
            ar[in] = i;
        }

        bool check = false;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                int temp = 2*v[j]-v[i];
                if(temp>0&&temp<=n){

                    if(ar[temp]>j){

                        check = true;
                    }
                }

                if(check)break;
            }

            if(check)break;
        }

        if(check)cout << "no" << endl;
        else cout << "yes" << endl;
    }

    return 0;
}
