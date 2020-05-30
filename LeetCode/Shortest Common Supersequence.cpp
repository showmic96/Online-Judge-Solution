class Solution {
public:
    int dp[1005][1005];
    int f(int i , int j , string &s , string &t){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==s.size()&&j==t.size()){
            return 0;
        }
        else if(i==s.size()){
            return dp[i][j] = f(i, j+1 , s , t) + 1;
        }
        else if(j==t.size()){
            return dp[i][j] = f(i+1 , j , s , t) + 1;
        }
        int value = 1e9;
        if(s[i]==t[j])value = min(value , f(i+1 , j+1, s , t)+1);
        value = min(value , f(i+1 , j , s , t)+1);
        value = min(value , f(i , j+1 , s , t)+1);
        return dp[i][j] = value;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp , -1 , sizeof(dp));
        int ans = f(0 , 0 , str1 , str2);
        int lim = ans , i = 0 , j = 0;
        string s = "";
        for(int i1=0;i1<lim;i1++){
            if(i==str1.size()){
                s+=str2[j];
                j++;
            }
            else if(j==str2.size()){
                s+=str1[i];
                i++;
            }
            else{
                if(str1[i]==str2[j]&&i1+f(i+1 , j+1 , str1 , str2)+1==ans){
                    s+=str1[i];
                    i++;
                    j++;
                }
                else if(i1+f(i+1 , j, str1 , str2)+1==ans){
                    s+=str1[i];
                    i++;
                }
                else{
                    s+=str2[j];
                    j++;
                }
            }
        }
        return s;
    }
};