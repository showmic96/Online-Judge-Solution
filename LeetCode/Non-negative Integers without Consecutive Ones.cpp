class Solution {
public:
    int dp[35][2][2];
    vector<int>v;
    void make(int x){
        v.clear();
        while(x){
            v.push_back(x%2);
            x/=2;
        }
        reverse(v.begin(), v.end());
    }
    int f(int i , int last , int smaller){
        if(i==v.size())return 1;
        if(dp[i][last][smaller]!=-1)return dp[i][last][smaller];
        int lim = v[i] , value = 0;
        if(smaller)lim = 1;
        for(int j=0;j<=lim;j++){
            if(j==1&&last==1)continue;
            value+=f(i+1 , j , smaller||(j<lim));
        }
        return dp[i][last][smaller] = value;
    }
    int findIntegers(int num) {
        make(num);
        memset(dp , -1 , sizeof(dp));
        return f(0 , 0 , 0);
    }
};