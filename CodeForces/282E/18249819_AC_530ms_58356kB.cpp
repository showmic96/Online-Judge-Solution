// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{

    bool endmark;
    node* next[3];
    node()
    {
        endmark = false;
        for(int i=0;i<2;i++)
            next[i] = NULL;
    }
}*root;

void in(string str , int len)
{
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = str[i] - '0';
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;

}
ll sear(string str , int len)
{
    ll ans = 0;
    node* curr = root;
    for(int i=0;i<len;i++){
        int id = str[i] - '0';
        id^=1;
        ans*=2;
        if(curr->next[id]==NULL){
            curr = curr->next[id^1];
        }
        else{
            curr = curr->next[id];
            ans+=1;
        }
    }
    return ans;
}

string make(ll x)
{
    string temp = "";
    while(x){

        temp+=x%2+'0';
        x/=2;
    }
    while(temp.size()<44)temp+="0";
    reverse(temp.begin() , temp.end());
    return temp;
}

ll ar[100005];

int main(void)
{
    int n;
    scanf("%d",&n);
    ll cur = 0 , ans = 0;
    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        cur^=in;
        ar[i] = cur;
    }
    root = new node();
    in(make(0) , 44);
    ans = cur;
    for(int i=0;i<n;i++){

        ll temp = cur^ar[i];
        ans = max(ans , sear(make(temp) , 44));
        in(make(ar[i]) , 44);
    }
    printf("%lld\n",ans);
    return 0;
}
