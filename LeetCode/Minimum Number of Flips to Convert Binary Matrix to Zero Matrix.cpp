class Solution {
public:
    int n , m , dp[(1<<9)+5];
    int dx[5] = {0 , +1 , -1 , 0 , 0};
    int dy[5] = {0 , 0 , 0 , +1 , -1};
    int Set(int N,int pos){return N=N | (1<<pos);}
    int Reset(int N,int pos){return N= N & ~(1<<pos);}
    bool Check(int N,int pos){return (bool)(N & (1<<pos));}
    int get(int i , int j){
        return i*m+j;
    }
    int f(int mask){
        if(mask==0)return 0;
        if(dp[mask]!=-1)return dp[mask];
        dp[mask] = 1e3;
        int value = 1e3;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = mask;
                for(int k=0;k<5;k++){
                    int tx = i+dx[k];
                    int ty = j+dy[k];
                    if(tx>=0&&ty>=0&&tx<n&&ty<m){
                        int now = get(tx , ty);
                        if(Check(temp , now)==false){
                            temp = Set(temp , now);
                        }
                        else{
                            temp = Reset(temp , now);
                        }
                    }
                }
                value = min(value , f(temp)+1);
            }
        }
        return dp[mask] = value;
    }
    int minFlips(vector<vector<int>>& mat) {
        n = mat.size() , m = mat[0].size();
        memset(dp , -1 , sizeof(dp));
        int mask = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)mask = Set(mask , get(i , j));
            }
        }
        int ans = f(mask);
        if(ans>=1e3)ans = -1;
        return ans;
    }
};