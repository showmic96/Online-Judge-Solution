class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int lvl[n][n];
        int dx[] = {0 , 0 , -1 , +1};
        int dy[] = {+1 , -1 , 0 , 0};
        
        memset(lvl , -1 , sizeof(lvl));
        queue<int>current;
        int ans = -1;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    current.push(i);
                    current.push(j);
                    lvl[i][j] = 0;
                }
            }
        }
        
        while(!current.empty()){
            int u = current.front();current.pop();
            int v = current.front();current.pop();
            for(int i=0;i<4;i++){
                int tx = u+dx[i];
                int ty = v+dy[i];
                if(tx<0||ty<0||tx>=n||ty>=n)continue;
                if(grid[tx][ty]==0&&lvl[tx][ty]==-1){
                    current.push(tx);
                    current.push(ty);
                    lvl[tx][ty] = lvl[u][v] + 1;
                    ans = max(ans , lvl[u][v] + 1);
                }
            }
        }
        return ans;
    }
};