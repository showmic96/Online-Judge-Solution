// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans;

struct node{

    bool endmark;
    node *next[7];
    ll counter;

    node(){

        counter = 0;
        endmark = false;

        for(int i=0;i<6;i++){

            next[i] = NULL;
        }
    }

} *root;

int get(char x)
{
    if(x=='A')return 0;
    if(x=='C')return 1;
    if(x=='G')return 2;
    return 3;
}

void ins(string str , int len)
{
    node* cur = root;

    for(int i=0;i<len;i++){

        int id = get(str[i]);

        if(cur->next[id]==NULL){

            cur->next[id] = new node();
        }

        cur->next[id]->counter++;

        cur = cur->next[id];
    }

    cur->endmark = true;
}

void dfs(node *cur , int len)
{

    ans = max(ans , cur->counter*len);

    for(ll i=0;i<4;i++){

        if(cur->next[i]){

            dfs(cur->next[i] , len+1);
        }
    }

}

void del(node* cur)
{
    for(int i=0;i<6;i++){

        if(cur->next[i]){

            del(cur->next[i]);
        }
    }

    delete(cur);
}

char ar[1000];

int main(void)
{

    int t , c = 0;
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

        ans = 1;

        dfs(root , 0);

        printf("Case %d: %lld\n",++c ,ans);

        del(root);
    }
    return 0;
}
