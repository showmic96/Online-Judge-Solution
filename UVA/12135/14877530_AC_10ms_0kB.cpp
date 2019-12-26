// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , fin;
int sum[105] , lvl[(1<<15)+10];;
char ar[105];

int Set(int n , int pos)
{
    return n|(1<<pos);
}

void bfs()
{
    queue<int>current;
    current.push(0);
    lvl[0] = 0;
    
    while(!current.empty()){
        
        int u = current.front();
        current.pop();
        
        for(int i=0;i<m;i++){
            
            int v = u^sum[i];

            if(lvl[v]==-1){
                
                current.push(v);
                lvl[v] = lvl[u]+1;
            }
        }
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n , &m);
        memset(sum , 0 , sizeof(sum));
        memset(lvl , -1 , sizeof(lvl));
        
        for(int i=0;i<m;i++){
            
            int in;
            scanf("%d",&in);
            
            for(int j=0;j<in;j++){
                
                int in;
                scanf("%d",&in);
                sum[i] = Set(sum[i] , in);
            }
        }
        
        bfs();
        
        int q;
        scanf("%d",&q);
        
        printf("Case %d:\n",++c);
        
        while(q--){
            scanf("%s",&ar);

            int mask = 0;
            for(int i=0;i<strlen(ar);i++){
                
                if(ar[i]=='1')mask = Set(mask , strlen(ar)-1-i);
            }

            printf("%d\n",lvl[mask]);
        }
        printf("\n");
    }
    return 0;
}