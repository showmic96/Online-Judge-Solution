class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size() , ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cnt = 0;
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(i+k<n&&j+l<n){
                            if(A[i+k][j+l]&B[k][l]==1)cnt++;
                        }
                    }
                }
                ans = max(ans , cnt);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cnt = 0;
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(i+k<n&&j+l<n){
                            if(B[i+k][j+l]&A[k][l]==1)cnt++;
                        }
                    }
                }
                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};