// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[50][50] , br[50][50];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> br[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ar[i][j]>br[i][j])swap(ar[i][j] , br[i][j]);
        }
    }
    bool valid = true;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(ar[i][j-1]>=ar[i][j])valid = false;
        }
    }
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            if(ar[i-1][j]>=ar[i][j])valid = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(br[i][j-1]>=br[i][j])valid = false;
        }
    }
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            if(br[i-1][j]>=br[i][j])valid = false;
        }
    }
    if(valid)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
