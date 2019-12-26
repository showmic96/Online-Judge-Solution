// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string , int>mp , level;

void bfs(string st , string en)
{
    queue<string>current;
    current.push(st);
    if(mp[st]==1)return ;
    if(mp[en]==1)return ;
    level[st] = 1;

    while(!current.empty()){

        string temp = current.front();
        current.pop();
        
        if(mp[temp]==1)continue;
        
        //cout << temp << endl;

        string temp2 = temp;

        temp2[0] = 'a'+(temp2[0]-'a'+1)%26;

        if(level[temp2]==0){

            current.push(temp2);
            level[temp2] = level[temp]+1;
        }

        temp2 = temp;

        temp2[0] = 'a'+(temp2[0]-'a'-1+26)%26;

        if(level[temp2]==0){

            current.push(temp2);
            level[temp2] = level[temp]+1;
        }

        temp2 = temp;

        temp2[1] = 'a'+(temp2[1]-'a'+1)%26;

        if(level[temp2]==0){

            current.push(temp2);
            level[temp2] = level[temp]+1;
        }

        temp2 = temp;

        temp2[1] = 'a'+(temp2[1]-'a'-1+26)%26;

        if(level[temp2]==0){

            current.push(temp2);
            level[temp2] = level[temp]+1;
        }

        temp2 = temp;

        temp2[2] = 'a'+(temp2[2]-'a'+1)%26;

        if(level[temp2]==0){

            current.push(temp2);
            level[temp2] = level[temp]+1;
        }

        temp2 = temp;

        temp2[2] = 'a'+(temp2[2]-'a'-1+26)%26;

        if(level[temp2]==0){

            current.push(temp2);
            level[temp2] = level[temp]+1;
        }
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        string st , en;
        cin >> st >> en;

        int n;
        scanf("%d", &n);
        vector<string>v;
        
        mp.clear();
        level.clear();
        
        for(int l=0;l<n;l++){

            string in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;

            int si1 = in1.size();
            int si2 = in2.size();
            int si3 = in3.size();

            for(int i=0;i<si1;i++){

                for(int j=0;j<si2;j++){

                    for(int k=0;k<si3;k++){

                        string temp = "";
                        temp+=in1[i];temp+=in2[j];temp+=in3[k];
                        mp[temp] = 1;
                    }
                }
            }
        }

        bfs(st , en);

        int ans = level[en];

        printf("Case %d: %d\n",++c , ans-1);
    }
    return 0;
}
