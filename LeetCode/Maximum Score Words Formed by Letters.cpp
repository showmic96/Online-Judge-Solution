class Solution {
public:
    int tot[26];
    int mx = 0;
    
    void f(int i , int value , vector<string>& words , vector<int>& score){
        if(i==words.size()){
            mx = max(mx , value);
            return ;
        }
        f(i+1 , value , words , score);
        bool possible = true;
        for(int j=0;j<words[i].size();j++){
            tot[words[i][j]-'a']--;
            if(tot[words[i][j]-'a']<0)possible = false;
            value+=score[words[i][j]-'a'];
        }
        if(possible)f(i+1 , value , words, score);
        for(int j=0;j<words[i].size();j++){
            tot[words[i][j]-'a']++;
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(int i=0;i<letters.size();i++){
            tot[letters[i]-'a']++;
        }
        f(0 , 0 , words , score);
        return mx;
    }
};