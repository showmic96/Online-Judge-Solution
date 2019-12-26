// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<int>v;

bool f(int mid)
{
    int now = 0;
    for(int i=0;i<n;i++){
        int nxt = (v[i]+mid)%m;
        //if(mid==5)cout << now << " " << v[i] << " " << nxt << endl;
        if(nxt<=v[i]&&mid>0){
            if(nxt>=now)now = now;
            else if(v[i]>=now)now = v[i];
          //  cout << "HERE" << endl;
        }
        else{
            if(v[i]>=now)now = v[i];
            else if(nxt>=now)now = now;
            else return false;
        }
    }
    //cout << now << endl;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        v.push_back(in);
    }
    int hi = m , low = 0 , mid , t = 200 , ans = -1;
    while(t--){
        mid = (hi+low)/2;
        if(f(mid)){
            ans = mid;
            hi = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}
