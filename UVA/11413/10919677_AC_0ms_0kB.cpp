// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m;

vector<int>v;

bool check(int lim)
{
    int mt = m-1 , limt = lim;

    for(int i=0;i<n;i++){

        if(v[i]>limt){

            limt = lim;
            mt--;
        }

        if(v[i]>lim)return false;

        limt-=v[i];
    }

    if(mt>=0)return true;
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> m){

        v.clear();

        for(int i=0;i<n;i++){

            int in;
            cin >> in;
            v.push_back(in);
        }

        ll hi = 1e8 , low = 1 , mid , t = 200 , ans = 0;

        while(t--){

            mid = (hi+low)/2;

            if(check(mid)==true){

                ans = mid;

                hi = mid-1;
            }
            else{

                low = mid+1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
