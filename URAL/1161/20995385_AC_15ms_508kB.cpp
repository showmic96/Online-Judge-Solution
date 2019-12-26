// In the name the Allah the Most Merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<double>v(n);
    for(auto &x:v)cin >> x;
    sort(v.begin() , v.end());
    if(v.size()==1){
        cout << setprecision(2) << fixed << v[0] << endl;
    }
    else{
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        double now = 2.00*sqrt(v[0]*v[1]);
        for(int i=2;i<v.size();i++){
            now = 2.00*sqrt(v[i]*now);
        }
        cout << setprecision(2) << fixed << now << endl;
    }
    return 0;
}
