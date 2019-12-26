// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int ar[100005] , w , l;

bool f(int mid)
{
    memset(ar , 0 , sizeof(ar));

    ar[max(0 , w-l)] -= mid;

    for(int i=w;i>=1;i--){

        ar[i]+=ar[i+1]+v[i];
        if(ar[i]<0)return false;

        ar[max(0 , i-l)]-=v[i];
    }

    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> w >> l;

    v.push_back(0);

    for(int i=0;i<w-1;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    int hi = 1e9+9 , low = 0 , mid , ans = -1 , t = 50;

    while(t--){

        mid = (hi+low)/2;

        if(f(mid)==true){

            ans = mid;
            low = mid+1;
        }
        else{

            hi = mid-1;
        }
    }

    cout << ans << endl;

    return 0;
}
