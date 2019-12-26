// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    bool blank = false;
    while(cin >> n){

        if(blank==true)cout << '\n';blank = true;
        vector<string>v;
        map<string , int>mp;

        memset(ans , 0 , sizeof(ans));

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;
            v.push_back(ar);
            mp[ar] = i+1;
        }

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;

            int in1 , in2;
            cin >> in1 >> in2;

            int temp = in1;
            if(in2>0)temp = in1/in2;

            for(int j=0;j<in2;j++){

                string t;
                cin >> t;

                ans[mp[t]]+=temp;
            }

            ans[mp[ar]]-=temp*in2;
        }

        for(int i=0;i<n;i++){

            cout << v[i] << " " << ans[i+1] << endl;
        }
    }

    return 0;
}
