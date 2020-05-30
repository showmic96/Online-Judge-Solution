class Solution {
public:
    vector<pair<int , int> > v;
    int dp[605][105][105];
    int f(int i , int c1 , int c2){
        if(i==v.size())return 0;
        if(dp[i][c1][c2]!=-1)return dp[i][c1][c2];
        int value = f(i+1 , c1 , c2);
        if(v[i].first<=c1&&v[i].second<=c2){
            value = max(value , f(i+1 , c1-v[i].first , c2-v[i].second)+1);
        }
        return dp[i][c1][c2] = value;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(auto x:strs){
            int cnt1 = 0 , cnt2 = 0;
            for(auto d:x){
                if(d=='0')cnt1++;
                else cnt2++;
            }
            v.push_back({cnt1 , cnt2});
        }
        memset(dp , -1 , sizeof(dp));
        return f(0 , m , n);
    }
};