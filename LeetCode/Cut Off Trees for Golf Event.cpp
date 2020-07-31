class Solution {
public:
    typedef long long ll;
    ll ar[55][55];
    vector<pair< ll , pair<ll , ll> > > v;
    ll n, m;
    int lvl[55][55];
    int dx[4] = {0 , 0 , +1 , -1};
    int dy[4] = {+1 , -1 , 0 , 0};
    void bfs(int x , int y){
        memset(lvl , -1 , sizeof(lvl));
        lvl[x][y] = 0;
        queue<int>current;
        current.push(x);
        current.push(y);
        while(!current.empty()){
            int u = current.front();current.pop();
            int v = current.front();current.pop();
            for(int i=0;i<4;i++){
                int tx = u+dx[i];
                int ty = v+dy[i];
                if(tx>=0&&ty>=0&&tx<n&&ty<m){
                    if(ar[tx][ty]==0)continue;
                    if(lvl[tx][ty]==-1){
                        lvl[tx][ty] = lvl[u][v]+1;
                        current.push(tx);
                        current.push(ty);
                    }
                }
            }
        }
    }
    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();
        for(int i=0;i<forest.size();i++){
            for(int j=0;j<forest[i].size();j++){
                ar[i][j] = forest[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]>1){
                    v.push_back({ar[i][j] , {i , j}});
                }
            }
        }
        bfs(0 , 0);
        ll ans = 0;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            int x = v[i].second.first;
            int y = v[i].second.second;
            if(lvl[x][y]==-1)return -1;
            ans+=lvl[x][y];
            bfs(x , y);
        }
        return ans;
    }
};
