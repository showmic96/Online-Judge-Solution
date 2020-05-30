class Solution {
public:
    int ar[30005];
    int minKBitFlips(vector<int>& A, int k) {
        int cnt = 0 , now = 0;
        for(int i=0;i<A.size();i++){
            now^=ar[i];
            if(A[i]^now==0){
                if(i+k-1>=A.size())return -1;
                now^=1;
                cnt++;
                ar[i+k]^=1;
            }
        }
        return cnt;
    }
};