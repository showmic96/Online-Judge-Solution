// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    int counter = 0;
    for(int i=0;i<len;i++){
        int now = 0;
        for(int j=0;j<26;j++){
            if(cur->next[j])now++;
        }
        if(now>1)counter++;
        else if(cur->endmark==true)counter++;
        int id = str[i] - 'a';
        if(cur->next[id])cur = cur->next[id];
    }
    return counter;
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
int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    while(cin >> n){
        root = new node();
        vector<string>v;
        set<char>st;
        for(int i=0;i<n;i++){
            string ar;
            cin >> ar;
            v.push_back(ar);
            ins(ar , ar.size());
            st.insert(ar[0]);
        }
        //ins("a" , 1);
        if(st.size()==1)ins("b" , 1);
        double tot = 0;
        for(int i=0;i<v.size();i++){
            tot+=max(1, ser(v[i] , v[i].size()));
            //cout << tot << endl;
        }
        cout << setprecision(2) << fixed << (tot/(double)n)+0.0001 << endl;
        del(root);
    }
    return 0;
}
