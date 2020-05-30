class Solution {
public:
    int dp[1105][1105];
    int f(int i , int last , vector<int>& s){
        if(i==s.size()-1){
            return 1;
        }
        if(dp[i][last]!=-1)return dp[i][last];
        int value = 0;
        if(i==0){
            for(int j=i+1;j<s.size();j++){
                if(s[j]-s[i]==1)
                    value = max(value , f(j , i , s));
                else break;
            }
        }
        else{
            for(int j=i+1;j<s.size();j++){
                if(s[j]-s[i]==s[i]-s[last]+1||s[j]-s[i]==s[i]-s[last]-1||s[j]-s[i]==s[i]-s[last])
                    value = max(value , f(j , i , s));
                else if(s[j]-s[i]>s[i]-s[last]+4)break;
            }
        }
        return dp[i][last] = value;
    }
    bool canCross(vector<int>& stones) {
        memset(dp , -1 , sizeof(dp));
        return f(0 , 0 , stones);
    }
};