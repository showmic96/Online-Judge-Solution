class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for(int i=0;i<satisfaction.size();i++){
            int temp = 0;
            for(int j=0;j<satisfaction.size();j++){
                if(i+j>=satisfaction.size())break;
                temp+=(j+1)*satisfaction[i+j];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};