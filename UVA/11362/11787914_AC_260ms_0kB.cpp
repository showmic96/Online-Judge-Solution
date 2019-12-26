// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct node{

    bool endmark;
    node *next[27];

    node(){

        endmark = false;
        for(int i=0;i<26;i++){

            next[i] = NULL;
        }
    }

} *root;

void ins(char* str , int len)
{
    node * cur = root;

    bool last = false;

    for(int i=0;i<len;i++){

        int id = str[i]-'0';
        if(cur->next[id]==NULL){

            cur->next[id] = new node();
            last = true;
        }

        else last = false;

        cur->endmark = false;

        cur = cur->next[id];
    }

    if(last==true)cur->endmark = true;
}

bool serach(string str , int len)
{
    node * cur = root;

    for(int i=0;i<len;i++){

        int id = str[i]-'0';

        cur = cur->next[id];
    }

    return cur->endmark;
}

void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        root = new node();

        int n;
        scanf("%d",&n);

        char ar[15];

        vector<string>v;

        for(int i=0;i<n;i++){

            scanf("%s",&ar);

            ins(ar , strlen(ar));

            string temp = "";

            for(int i=0;i<strlen(ar);i++)temp+=ar[i];

            v.push_back(temp);
        }

        bool ch = true;

        for(int i=0;i<n;i++){

            if(serach(v[i] , v[i].size())==false)ch = false;
        }

        if(ch==true)printf("YES\n");
        else printf("NO\n");

        del(root);
    }
    return 0;
}
