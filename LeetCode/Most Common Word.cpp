class Solution {
public:
    bool check(char x){
        if(x=='!'||x=='?'||x==','||x==';'||x=='.'||x=='\'')return true;
        return false;
    }
    string get(string ar){
        string temp = "";
        for(int i=0;i<ar.size();i++){
            if(ar[i]=='!'||ar[i]=='?'||ar[i]==','||ar[i]==';'||ar[i]=='.'||ar[i]=='\'')continue;
            if(ar[i]>='A'&&ar[i]<='Z')ar[i]+=32;
            temp+=ar[i];
        }
        return temp;
    }
    string mostCommonWord(string p, vector<string>& banned) {
        map<string , int>mp1 , mp2;
        for(int i=0;i<banned.size();i++){
            mp2[banned[i]] = 1;
        }
        string ans , temp = "";
        p+= " ";
        int mx = 0;
        for(int i=0;i<p.size();i++){
            if(check(p[i])==true||p[i]==' '){
                temp = get(temp);
                if(temp=="")continue;
                if(mp2.find(temp)==mp2.end()){
                    mp1[temp]++;
                    if(mp1[temp]>mx){
                        ans = temp;
                        mx = mp1[temp];
                    }
                }
                temp = "";
            }
            else temp+=p[i];
        }
        return ans;
    }
};
