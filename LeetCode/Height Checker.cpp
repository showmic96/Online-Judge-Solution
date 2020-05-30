class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v = heights;
        sort(v.begin(), v.end());
        int cnt = 0 , mx = 0;
        for(auto i = 0;i<v.size();i++){
            if(v[i]!=heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};