class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int>mp;
        for(auto c:C){
            for(auto d:D){
                mp[c+d]++;
            }
        }
        int cnt = 0;
        for(auto a:A){
            for(auto b:B){
                if(mp.find(-(a+b))!=mp.end()){
                    cnt+=mp[-(a+b)];
                }
            }
        }
        return cnt;
    }
};