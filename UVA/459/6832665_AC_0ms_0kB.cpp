#include<bits/stdc++.h>
using namespace std;

vector<int>edge[150];
bool isVisited[100];
int counter = 0;

void setUp()
{
    counter = 0;
    for(int i=0;i<100;i++){

        edge[i].clear();
        isVisited[i]=false;
    }
}

void bfs(int a)
{
    queue<int>current;
    int temp , siz;

    isVisited[a]=true;

    current.push(a);

    while(!current.empty()){

        temp = current.front();
        current.pop();

        siz = edge[temp].size();
       // cout << "YES";
        for(int i=0;i<siz;i++){

            if(isVisited[edge[temp][i]]==false){

                isVisited[edge[temp][i]]=true;

                current.push(edge[temp][i]);
            }
        }

    }
}




int main(void)
{
    int a , space =1;

    cin >> a;

    char X;

    string ar , br;
    scanf("\n");
    
    while(a--){
        
        if(!space)cout << endl;space=0;
         
        setUp();
        //getchar();
        getline(cin , br);
        
       // cout << br << endl;

        while(1){

            getline(cin , ar);

            if(ar==""){break;}

            else {

                edge[int(ar[0])-'A'].push_back(int(ar[1])-'A');
                edge[int(ar[1])-'A'].push_back(int(ar[0])-'A');
            }
            ar="";
        }

        int total  = (int)br[0] - 'A'+1;

        for(int i=0;i<total;i++){

            if(isVisited[i]==false){counter++;bfs(i);}
        }
        cout << counter << endl;
    }
    
    return 0;
}
