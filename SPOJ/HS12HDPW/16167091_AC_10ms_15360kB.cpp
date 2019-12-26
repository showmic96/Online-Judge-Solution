// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> get(int x)
{
    vector<int>temp;

    while(x){

        temp.push_back(x%2);
        x/=2;
    }

    if(temp.size()!=6)temp.push_back(0);
    return temp;
}

int re(vector<int>v)
{
    reverse(v.begin() , v.end());
    int ans = 0;

    for(int i=0;i<v.size();i++){

        ans*=2;
        ans+=v[i];
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;

        vector<int>ans;

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;

            vector<int>value;

            for(int i=0;i<6;i++){

                vector<int>v = get(ar[i]);
                value.push_back(v[i]);
            }

            int num = re(value);
            ans.push_back(num);

            value.clear();

            for(int i=0;i<6;i++){

                vector<int>v = get(ar[i]);
                value.push_back(v[(i+3)%6]);
            }

            num = re(value);
            ans.push_back(num);
        }

        string br;
        cin >> br;

        for(int i=0;i<ans.size();i++){

            cout << br[ans[i]];
        }
        cout << endl;
    }
    return 0;
}
