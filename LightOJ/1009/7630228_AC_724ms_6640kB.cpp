// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 7;

vector<int>edges[MAX];
map<int, char>id;
int b_counter ,w_counter;
bool isVisited[MAX];
int ans ;

void set_up()
{
    for(int i=0;i<MAX;i++){
        edges[i].clear();

        for(int j=0;j<MAX;j++)isVisited[i]=false;

    }
}

void bfs(int a)
{
    queue<int>current;
    current.push(a);
    id[a] = 'w';
    w_counter++;

    while(!current.empty()){

        int temp = current.front();
        current.pop();
        isVisited[temp] = true;

        int si = edges[temp].size();

        for(int i=0;i<si;i++){

            if(!id[edges[temp][i]]){

                current.push(edges[temp][i]);
                if(id[temp]=='w'){b_counter++;id[edges[temp][i]] = 'b';}
                else {w_counter++;id[edges[temp][i]] = 'w';}
            }
        }
    }

    ans +=max(w_counter , b_counter);
    w_counter = b_counter = 0;
}

int main(void)
{
    int t , n , in1 , in2;
    scanf("%d",&t);//cin >> t;

    for(int i=0;i<t;i++){

        set_up();
        id.clear();
        b_counter = w_counter = ans = 0;

        scanf("%d",&n);//cin >> n;
        int hi = 0;
        for(int j=0;j<n;j++){

            cin >> in1 >> in2;
            hi = max(in1 , max(in2 , hi));
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);

        }

        for(int i=1;i<=hi;i++)if(isVisited[i]==false&&edges[i].size()>0)bfs(i);

        printf("Case %d: %d\n",i+1 , ans);
    }

    return 0;
}
