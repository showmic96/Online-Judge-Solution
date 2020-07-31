class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt = 0;
        for(int i=0;i<words.size();i++){
            bool check = true;
            map<char , int>mp;
            for(int j=0;j<chars.size();j++){
                mp[chars[j]]++;
            }
            for(int j=0;j<words[i].size();j++){
                mp[words[i][j]]--;
                if(mp[words[i][j]]<0){
                    check = false;
                    break;
                }
            }
            if(check)cnt+=words[i].size();
        }
        return cnt;
    }
};
