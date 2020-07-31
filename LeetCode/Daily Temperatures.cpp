class Solution {
public:
    int v[105];
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ret;
        memset(v, -1 , sizeof(v));
        reverse(t.begin(), t.end());
        for(int i=0;i<t.size();i++){
            int ans = -1;
            v[t[i]] = i;
            for(int j=t[i]+1;j<=101;j++){
                if(v[j]!=-1){
                    ans = max(ans , v[j]);
                }
            }
            if(ans==-1)ans = 0;
            else ans = i - ans;
            ret.push_back(ans);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
