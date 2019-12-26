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

void ins(string str , int len)
{
    node* cur = root;

    for(int i=0;i<len;i++){

        int id = str[i] - 'a';

        if(cur->next[id]==NULL){

            cur->next[id] = new node();
        }


        cur->next[id]->counter++;

        cur = cur->next[id];
    }

    cur->endmark = true;
}

int ser(string str , int len)
{
    node* cur = root;

    int mx = 1e9;

    for(int i=0;i<len;i++){

        int id = str[i] - 'a';

        if(cur->next[id])cur = cur->next[id];
        else return 0;

    }

    return cur->counter;
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

string ar;

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , q;
    cin >> n >> q;
    root = new node();
    while(n--){
        string ar;
        cin >> ar;
        ins(ar , ar.size());
    }
    while(q--){
        string ar;
        cin >> ar;
        int ans = ser(ar , ar.size());
        cout << ans << endl;
    }

    return 0;
}
