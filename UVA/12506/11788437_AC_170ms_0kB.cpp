// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct node{

    bool endmark;
    node *next[27];
    int counter;

    node(){

        counter = 0;
        endmark = false;

        for(int i=0;i<26;i++){

            next[i] = NULL;
        }
    }

} *root;

void ins(char* str , int len)
{
    node* cur = root;

    for(int i=0;i<len;i++){

        int id = str[i] - 'a';

        if(cur->next[id]==NULL){

            cur->next[id] = new node();
        }


        cur->counter++;

        cur = cur->next[id];
    }

    cur->endmark = true;
}

int ser(string str , int len)
{
    node* cur = root;

    for(int i=0;i<len;i++){

        int id = str[i] - 'a';

        if(cur->counter==1)return i;

        cur = cur->next[id];

    }

    return len;
}

void del(node* cur)
{
    for(int i=0;i<26;i++){

        if(cur->next[i]){

            del(cur->next[i]);
        }
    }

    delete(cur);
}

char ar[1000005];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        root = new node();

        int n;
        scanf("%d",&n);

        vector<string>v;

        for(int i=0;i<n;i++){

            scanf("%s",&ar);

            ins(ar , strlen(ar));

            string temp = "";

            for(int j=0;j<strlen(ar);j++)temp+=ar[j];

            v.push_back(temp);
        }

        int ans = 0;

        for(int i=0;i<n;i++){

            ans+=ser(v[i] , v[i].size());
        }

        printf("%d\n",max(1, ans));

        del(root);
    }
    return 0;
}
