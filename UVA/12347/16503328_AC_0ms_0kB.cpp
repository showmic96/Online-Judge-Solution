// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct tree{

    int val;
    tree *l , *r;
    bool used;

} *head;

void in(tree *now , int val)
{
    if(now->used==false){

        now->used = true;
        now->val = val;
        now->l = new tree();
        now->l->used = false;
        now->r = new tree();
        now->r->used = false;
        return ;
    }

    if(val<now->val)in(now->l , val);
    else in(now->r , val);
}

void print(tree *now)
{
    if(now->used==false)return ;
    print(now->l);
    print(now->r);
    printf("%d\n",now->val);
}

int main(void)
{
    head = new tree();
    head->used = false;

    int n;
    while(scanf("%d",&n)==1){

        in(head , n);
    }

    print(head);

    return 0;
}
