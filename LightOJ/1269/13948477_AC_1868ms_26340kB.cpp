// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{

    node* next[3];
    node(){

        next[0] = NULL;
        next[1] = NULL;
        next[2] = NULL;
    }
} *root;

void insert(string str , int len)
{
    node *cur = root;
    for(int i=0;i<len;i++){
        int id = str[i] - '0';

        if(cur->next[id]==NULL)
            cur->next[id] = new node();

        cur = cur->next[id];
    }
}

void del(node* cur)
{
    for (int i = 0; i < 2; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

ll getMin(string str , int len)
{
    ll val = 0;
    node* cur = root;
    for(int i=0;i<len;i++){

        val*=2;

        int id = str[i] - '0';
        if(cur->next[id]==NULL){
            val+=1;
            id = (id^1);
            cur = cur->next[id];
        }
        else cur = cur->next[id];
    }
    return val;
}

ll getMax(string str , int len)
{
    ll val = 0;
    node* cur = root;
    for(int i=0;i<len;i++){

        val*=2;

        int id = str[i] - '0';
        id^=1;
        if(cur->next[id]==NULL){
            id = (id^1);
            cur = cur->next[id];
        }
        else {
            cur = cur->next[id];
            val+=1;
        }
    }
    return val;
}

string make(ll x)
{
    string temp = "";
    while(x){
        temp+=x%2+'0';
        x/=2;
    }
    while(temp.size()<32)temp+='0';
    reverse(temp.begin() , temp.end());

    return temp;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        root = new node();

        int n;
        scanf("%d",&n);

        ll mi = 1e18 , mx = 0;
        vector<ll>v;

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
            if(i)v[i] = in^v[i-1];
        }
        insert(make(0) , 32);

        for(int i=0;i<n;i++){
            mi = min(mi , getMin(make(v[i]) , 32));
            mx = max(mx , getMax(make(v[i]) , 32));
            insert(make(v[i]) , 32);
        }

        printf("Case %d: %lld %lld\n",++c , mx , mi);
        del(root);
    }
    return 0;
}
