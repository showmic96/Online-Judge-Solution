class Solution {
public:
    const static int MAX = 1e5+9;
    vector<int>edges[MAX], t;
    int dfs(int u , int par = -1){
        int value = 0;
        if(edges[u].size())value+=t[u];
        for(auto v:edges[u]){
            value = max(value , dfs(v , u)+t[u]);
        }
        return value;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        t = informTime;
        for(int i=0;i<n;i++){
            if(manager[i]==-1)continue;
            edges[manager[i]].push_back(i);
        }
        return dfs(headID);
    }
};
