class Solution {
public:
    bool dp[25][25];
    int cnt = 0 , need = 0;
    int dx[4] = {0 , 0 , +1 , -1};
    int dy[4] = {+1 , -1 , 0 , 0};
    
    void f(int i , int j , int tot , vector<vector<int>>& grid){
        if(dp[i][j]==true)return ;
        if(grid[i][j]==-1)return ;
        if(grid[i][j]==2){
            if(tot==need+1)cnt++;
            return ;
        }
        dp[i][j] = true;
        for(int i1=0;i1<4;i1++){
            int tx = dx[i1]+i;
            int ty = dy[i1]+j;
            if(tx>=0&&tx<grid.size()&&ty>=0&&ty<grid[0].size()){
                f(tx , ty , tot+1 , grid);
            }
        }
        dp[i][j] = false;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        memset(dp , false , sizeof(dp));
        for(auto element: grid){
            for(auto cell: element){
                if(cell==0)need++;
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    f(i , j , 0 , grid);
                }
            }
        }
        return cnt;
    }
};