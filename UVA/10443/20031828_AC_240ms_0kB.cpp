// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[105] , br[105];
int dx[] = {0 , 0 , +1 , -1};
int dy[] = {+1 , -1 , 0 , 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    bool blank = false;
    int t;
    cin >> t;
    while(t--){
        if(blank)cout << endl;blank = true;
        int n , m , k;
        cin >> n >> m >> k;
        for(int i=0;i<n;i++)cin >> ar[i];
        while(k--){
            for(int i=0;i<n;i++)br[i] = ar[i];
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    for(int k=0;k<4;k++){
                        int tx = i+dx[k];
                        int ty = j+dy[k];
                        if(tx>=0&&tx<n&&ty>=0&&ty<m){
                            if(ar[i][j]=='R'&&ar[tx][ty]=='S'){
                                br[tx][ty] = 'R';
                            }
                            if(ar[i][j]=='S'&&ar[tx][ty]=='P'){
                                br[tx][ty] = 'S';
                            }
                            if(ar[i][j]=='P'&&ar[tx][ty]=='R'){
                                br[tx][ty] = 'P';
                            }
                        }
                    }
                }
            }
            for(int i=0;i<n;i++)ar[i] = br[i];
        }
        for(int i=0;i<n;i++)cout << ar[i] << endl;
    }

    return 0;
}
