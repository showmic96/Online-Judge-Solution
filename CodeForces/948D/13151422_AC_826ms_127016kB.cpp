// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct node{

    bool endmark;
    node* next[2+1];
    int counter;

    node(){

        endmark = false;
        counter = 0;
        for(int i=0;i<2;i++)next[i] = NULL;
    }
} *root;

void ins(string str , int len)
{
    node* curr = root;

    for(int i=0;i<len;i++){

        int id = str[i] - '0';

        if(curr->next[id]==NULL)curr->next[id] = new node();
        curr->counter++;
        curr = curr->next[id];
    }
    curr->counter++;
    curr->endmark = true;
}

int ans(string str , int len)
{
    int ans = 0;
    node* curr = root;
    for(int i=0;i<len;i++){

        ans*=2;
        int id = str[i] - '0';

        if(curr->next[id]==NULL)id = id^1;
        else if(curr->next[id]->counter==0)id = id^1;
        curr->counter--;

        curr = curr->next[id];
        if(id!=str[i]-'0')ans+=1;
    }
    curr->counter--;
    return ans;
}

string make(int x)
{
    string temp = "";
    while(x){

        temp+='0'+x%2;
        x/=2;
    }

    while(temp.size()!=32)temp+='0';
    reverse(temp.begin() , temp.end());

    return temp;
}

int main(void)
{
    root = new node();
    int n;
    vector<int>v;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        ins(make(in) , 32);
    }

    for(int i=0;i<n;i++){

        printf("%d ",ans(make(v[i]) , 32));
    }

    return 0;
}
