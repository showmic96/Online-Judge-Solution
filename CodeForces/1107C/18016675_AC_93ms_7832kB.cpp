// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<char , ll > A , pair<char ,ll > B)
{
    return A.second>B.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , k , ans = 0;
    cin >> n >> k;

    vector<int>v(n);
    string ar;

    for(int i=0;i<n;i++){

        cin >> v[i];
    }
    cin >> ar;

    vector<pair<char , ll > > temp;

    for(int i=0;i<n;i++){

        if(temp.size()==0){

            temp.push_back({ar[i] , v[i]});
        }
        else{

            if(ar[i]==temp[0].first)temp.push_back({ar[i] , v[i]});
            else{

                sort(temp.begin() , temp.end() , cmp);
                for(int j=0;j<min((ll)temp.size() , k);j++)ans+=temp[j].second;
                temp.clear();
                temp.push_back({ar[i] , v[i]});
            }
        }
    }

    if(temp.empty()==false){

        sort(temp.begin() , temp.end() , cmp);
        for(int j=0;j<min((ll)temp.size() , k);j++)ans+=temp[j].second;
    }

    cout << ans << endl;

    return 0;
}
