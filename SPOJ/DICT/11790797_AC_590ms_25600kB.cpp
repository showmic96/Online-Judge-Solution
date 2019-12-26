// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

vector<string>ans;

struct node{

    bool endmark;
    node* next[27];

    node(){

        endmark = false;

        for(int i=0;i<26;i++){

            next[i] = NULL;
        }
    }
} *root ;

void ins(char* str , int len)
{
    node* cur = root;

    for(int i=0;i<len;i++){

        int id = str[i]-'a';

        if(cur->next[id]==NULL){

            cur->next[id] = new node();
        }

        cur = cur->next[id];
    }

    cur->endmark = true;
}

void del(node *cur)
{
    for(int i=0;i<26;i++){

        if(cur->next[i]){

            del(cur->next[i]);
        }
    }

    delete(cur);
}

void dfs(string ar , node* cur , int i, string temp)
{
    if(ar.size()>i){

        int id = ar[i]-'a';

        if(cur->next[id]){

            dfs(ar , cur->next[id] , i+1, temp+ar[i]);
        }
    }

    else{

        for(int j=0;j<26;j++){

            if(cur->next[j]){

                dfs(ar , cur->next[j] , i+1, temp+(char)('a'+j));
            }
        }
    }

    if(i>ar.size()&&cur->endmark==true)ans.push_back(temp);
}

char ar[22];

int main(void)
{
    root = new node();
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%s",&ar);
        ins(ar , strlen(ar));
    }

    int q , c = 0;

    scanf("%d",&q);

    while(q--){

        printf("Case #%d:\n",++c);
        scanf("%s",ar);

        string temp = "";

        for(int i=0;i<strlen(ar);i++)temp+=ar[i];

        node* root_t = root;

        ans.clear();

        dfs(temp , root_t , 0 , "");

        sort(ans.begin() , ans.end());

        //cout << ans.size() << endl;

        int si1 = ans.size();

        for(int i=0;i<si1;i++){

            int si2 = ans[i].size();

            for(int j=0;j<si2;j++){

                printf("%c",ans[i][j]);
            }

            printf("\n");
        }

        if(ans.size()==0)printf("No match.\n");
    }

    return 0;
}
