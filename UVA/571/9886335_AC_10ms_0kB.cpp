// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int x , y;
    string ar;

    node(int xt , int yt , string art){

        x = xt;
        y = yt;
        ar = art;
    }
};

bool visited[1005][1005];

void bfs(int c1 , int c2 , int n)
{
    queue<node>q;
    q.push(node(0 , 0 , ""));
    string ans;

    while(!q.empty()){

        int x = q.front().x;
        int y = q.front().y;

        string t = q.front().ar;

        q.pop();

        if(visited[x][y]==true)continue;
        visited[x][y] = true;

        if(y==n){

            ans = t;
            break;
        }

        q.push(node(0 , y , t+"0"));
        q.push(node(c1 , y , t+"1"));
        q.push(node(x , 0 , t+"2"));
        q.push(node(x , c2 , t+"3"));
        q.push(node(x-min(x , c2-y) , min(x , c2-y)+y , t+"4"));
        q.push(node(min(y ,  c1-x)+x , y-min(y, c1-x) , t+"5"));
    }

    int si = ans.size();

    for(int i=0;i<si;i++){

        if(ans[i]=='0')printf("empty A\n");
        if(ans[i]=='1')printf("fill A\n");
        if(ans[i]=='2')printf("empty B\n");
        if(ans[i]=='3')printf("fill B\n");
        if(ans[i]=='4')printf("pour A B\n");
        if(ans[i]=='5')printf("pour B A\n");
    }

    printf("success\n");
}

int main(void)
{
    int c1 , c2 , n;
    while(scanf("%d %d %d",&c1 , &c2 , &n)==3){

        memset(visited , false , sizeof(visited));
        bfs(c1 , c2 , n);
    }
    return 0;
}
