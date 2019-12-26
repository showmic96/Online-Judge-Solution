// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    bool blank = false;
    int t;
    cin >> t;
    while(t--){
        if(blank)cout << endl;blank = true;
        int n;
        cin >> n;
        vector<int>v1 , v2 , v3 , v4;
        vector<int>v;
        for(int i=0;i<n;i++){
            int in1 , in2 , in3 , in4;
            cin >> in1 >> in2 >> in3 >> in4;
            v1.push_back(in1);
            v2.push_back(in2);
            v3.push_back(in3);
            v4.push_back(in4);
        }
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                v.push_back(v1[i]+v2[j]);
            }
        }
        sort(v.begin() , v.end());
        int ans = 0;
        for(int i=0;i<v3.size();i++){
            for(int j=0;j<v4.size();j++){
                int now = v3[i]+v4[j];
                ans+=upper_bound(v.begin() , v.end() , -now)-lower_bound(v.begin() , v.end() , -now);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
