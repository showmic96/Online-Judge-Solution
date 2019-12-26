// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 13;
char ar[MAX+9][MAX+9];
int level[MAX+9][MAX+9] , check;
int c = 0;
int n , counter = 0;

bool isAlpha(char x)
{
    //cout << "Char " << x << endl;
    if(x>='A'&&x<='Z'){return true;}
    return false;
}

void bfs(int i , int j , char s , char d)
{
    queue<int>current;
    current.push(i);
    current.push(j);

    level[i][j] = 0;

    while(!current.empty()){
        //cout << i << " " << j << endl;
        i = current.front();current.pop();
        j = current.front();current.pop();

        if(ar[i][j]=='#')continue;

        if(ar[i][j]==d){

            c = min(c , level[i][j]);
            check = true;
            break;
        }

        if(isAlpha(ar[i][j])==true){

            if(ar[i][j]!=s){continue;}

            ar[i][j]= '.';
        }

        if(i+1<n){

            if(level[i+1][j]>level[i][j]+1){

                level[i+1][j] = level[i][j] + 1;
                current.push(i+1);
                current.push(j);
            }
        }

        if(j+1<n){

            if(level[i][j+1]>level[i][j]+1){

                level[i][j+1] = level[i][j] + 1;
                current.push(i);
                current.push(j+1);
            }
        }


        if(i-1>=0){

            if(level[i-1][j]>level[i][j]+1){

                level[i-1][j] = level[i][j] + 1;
                current.push(i-1);
                current.push(j);
            }
        }


        if(j-1>=0){

            if(level[i][j-1]>level[i][j]+1){

                level[i][j-1] = level[i][j] + 1;
                current.push(i);
                current.push(j-1);
            }
        }
    }
}

void setUp()
{
    for(int i=0;i<MAX;i++){

        for(int j=0;j<MAX;j++)level[i][j] = 1234567;
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        counter = 0;
        scanf("%d",&n);

        map<char , pair<int , int> > mp;

        for(int j=0;j<n;j++)cin >> ar[j];

        //for(int j=0;j<n;j++)cout << ar[j] << endl;

        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                if(isAlpha(ar[j][k])==true){

                    counter++;

                    mp[ar[j][k]] = make_pair(j , k);
                }
            }
        }

        int ans = 0;

        for(int j=0;j<counter-1;j++){

            check = false;
            setUp();
            c = 123456;

            bfs(mp['A'+j].first , mp['A'+j].second , 'A'+j , 'A'+j+1);

            if(check==false)break;

            ans+=c;
        }

        if(counter==1){check=true;ans=0;}

        //for(int i=0;i<n;i++)cout << ar[i] << endl;

        if(check==false)printf("Case %d: Impossible\n",i+1);
        else printf("Case %d: %d\n",i+1 , ans);

    }

    return 0;
}
