#include<bits/stdc++.h>
using namespace std;

vector<int>edges[25];
bool isVisited[25];
int level[25];

void setUp1()
{
    for(int i=0;i<25;i++)isVisited[i]=false;
}

void setUp2()
{
    for(int i=0;i<25;i++){
            isVisited[i]=false;
            edges[i].clear();

    }
}

void bfs(int from , int to)
{
    int temp , siz;
    queue<int>current;

    current.push(from);

    setUp1();

    isVisited[from]=true;

    level[from] = 1;

    while(!current.empty()){

        temp = current.front();
        current.pop();

        siz = edges[temp].size();

        for(int i=0;i<siz;i++){

            if(isVisited[edges[temp][i]]==false){

                isVisited[edges[temp][i]]=true;

                level[edges[temp][i]] = level[temp] + 1;

                current.push(edges[temp][i]);
            }
        }
    }
    if(from<10)cout << " " << from;
    else cout << from;
    cout <<" to "; 
    if(to<10)cout << " " <<  to;
    else cout << to;
    cout << ": "  << level[to]-1 << endl;

}

int main(void)
{
    int counter = 0;
    int a , b , c=1 , d , to , from;
    setUp2();

    while(cin >> a){

        for(int i=0;i<a;i++){

            cin >> b;

            edges[c].push_back(b);
            edges[b].push_back(c);
        }

        if(c==19){
            cin >> d;
            printf("Test Set #%d\n",++counter);
            for(int j=0;j<d;j++){

                cin >> from >> to;

                bfs(from , to);
            }
            cout << endl;
            setUp2();
            c=0;
        }

        c++;
        //setUp2();
    }
    
    return 0;
}
