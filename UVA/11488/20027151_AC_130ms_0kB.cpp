// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct node{
    bool endmark;
    node *next[2];
    int counter;
    node(){
        counter = 0;
        endmark = false;
        for(int i=0;i<2;i++){
            next[i] = NULL;
        }
    }
} *root;
int mx = 0;
void ins(string str , int len)
{
    node* cur = root;
    for(int i=0;i<len;i++){
        int id = str[i] - '0';
        if(cur->next[id]==NULL){
            cur->next[id] = new node();
        }
        cur->next[id]->counter++;
        mx = max(mx , cur->next[id]->counter*(i+1));
        cur = cur->next[id];
    }
    cur->endmark = true;
}

void del(node* cur)
{
    for(int i=0;i<2;i++){
        if(cur->next[i]){
            del(cur->next[i]);
        }
    }
    delete(cur);
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        root = new node();
        mx = 0;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            string ar;
            cin >> ar;
            ins(ar , ar.size());
        }
        cout << mx << endl;
        del(root);
    }

    return 0;
}
