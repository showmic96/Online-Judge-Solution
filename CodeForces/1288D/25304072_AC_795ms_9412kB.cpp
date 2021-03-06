// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5+9;
int ar[MAX][8] , n , m , val[(1<<8)+5];

pair<int , int> f(int x)
{
    memset(val , -1 , sizeof(val));
    for(int i=0;i<n;i++){
        int cur = 0;
        for(int j=0;j<m;j++){
            if(ar[i][j]>=x){
                cur^= (1<<j);
            }
        }
        val[cur] = i;
    }
    for(int i=0;i<(1<<m);i++){
        for(int j=0;j<(1<<m);j++){
            if( (i|j) == (1<<m)-1){
                if(val[i]!=-1&&val[j]!=-1){
                    return make_pair(val[i] , val[j]);
                }
            }
        }
    }
    return make_pair(-1 , -1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }
    int hi = 1e9 , low = 0 , t = 70;
    pair<int , int> ans;
    while(t--){
        int mid = (hi+low)/2;
        pair<int , int> temp = f(mid);
        if(temp.first!=-1){
            ans = temp;
            low = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans.first+1 << " " << ans.second+1 << endl;

    return 0;
}
