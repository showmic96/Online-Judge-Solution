// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;
const int MAX = 12345;
char ar[MAX][MAX];
int ans[MAX][MAX];
int n , m;
bool isVisited[MAX][MAX];

void setUp()
{
    for(int i=0;i<MAX;i++){

        for(int j=0;j<MAX;j++)isVisited[i][j] = false;
    }
}

void dfs(int i , int j , int v , char x)
{
    if(i>=n||j>=m)return ;
    if(i<0||j<0)return ;
    if(ar[i][j]!=x)return ;
    if(isVisited[i][j]==true)return;

    isVisited[i][j] = true;
    ans[i][j] = v;

    dfs(i+1 , j , v , x);
    dfs(i-1 , j , v , x);
    dfs(i , j+1 , v , x);
    dfs(i , j-1 , v , x);
    dfs(i+1 , j-1 , v , x);
    dfs(i-1 , j-1 , v , x);
    dfs(i+1 , j+1 , v , x);
    dfs(i-1 , j+1 , v , x);
}

int main(void)
{
    string line;
    n = 0;
    while(true){

        getline(cin , line);

        if(feof(stdin)||line[0]=='%'){

            setUp();
            int c = 1;
            map<char , int>mp;

            for(int i=0;i<n;i++){

                for(int j=0;j<m;j++){

                    if(isVisited[i][j]==false){

                        dfs(i , j , c++ , ar[i][j]);
                    }
                }
            }

            int mx[m];
            memset(mx ,0 , sizeof(mx));

            for(int i=0;i<m;i++){

                for(int j=0;j<n;j++){

                    mx[i] = max(mx[i],ans[j][i]);
                }
            }

            for(int i=0;i<n;i++){

                for(int j=0;j<m;j++){

                    if(j==0){
                        if(mx[j]>=1000&&ans[i][j]>=1000)cout << ""<< ans[i][j];
                        else if(mx[j]>=1000&&ans[i][j]>=100)cout << " "<< ans[i][j];
                        else if(mx[j]>=1000&&ans[i][j]>=10)cout << "  "<< ans[i][j];
                        else if(mx[j]>=1000&&ans[i][j]<10)cout << "   "<< ans[i][j];
                        else if(mx[j]>=100&&ans[i][j]>=100)cout <<"" << ans[i][j];
                        else if(mx[j]>=100&&ans[i][j]>=10)cout << " " << ans[i][j];
                        else if(mx[j]>=100&&ans[i][j]<10)cout << "  " << ans[i][j];
                        else if(mx[j]>=10&&ans[i][j]>=10)cout << "" << ans[i][j];
                        else if(mx[j]>=10&&ans[i][j]<10)cout << " " << ans[i][j];
                        else cout << "" << ans[i][j];
                    }

                    else{
                        
                        if(mx[j]>=1000&&ans[i][j]>=1000)cout << " "<< ans[i][j];
                        else if(mx[j]>=1000&&ans[i][j]>=100)cout << "  "<< ans[i][j];
                        else if(mx[j]>=1000&&ans[i][j]>=10)cout << "   "<< ans[i][j];
                        else if(mx[j]>=1000&&ans[i][j]<10)cout << "    "<< ans[i][j];
                        else if(mx[j]>=100&&ans[i][j]>=100)cout <<" " << ans[i][j];
                        else if(mx[j]>=100&&ans[i][j]>=10)cout << "  " << ans[i][j];
                        else if(mx[j]>=100&&ans[i][j]<10)cout << "   " << ans[i][j];
                        else if(mx[j]>=10&&ans[i][j]>=10)cout << " " << ans[i][j];
                        else if(mx[j]>=10&&ans[i][j]<10)cout << "  " << ans[i][j];
                        else cout << " " << ans[i][j];
                    }
                }

                cout << endl;
            }

            if(line[0]=='%')cout << "%" << endl;
            m = n = 0;

            if(feof(stdin))break;

        }

        else{

            m = 0;

            stringstream ss(line);
            while(ss >> ar[n][m])m++;
            n++;

        }

    }
    
    cout << "%" << endl;
    return 0;
}
