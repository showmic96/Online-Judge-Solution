// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>

using namespace std;

int counter = 0;
string ar[3];
bool taken[10];

bool possible(int i , int j)
{
    if(i>=3||j>=3)return false;
    if(i<0||j<0)return false;
    return true;
}

bool check2()
{
    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            if(ar[i][j]=='9')continue;

            if(possible(i+1 , j)==true){

                if(ar[i][j]+1==ar[i+1][j])continue;
            }

            if(possible(i-1 , j)==true){

                if(ar[i][j]+1==ar[i-1][j])continue;
            }

            if(possible(i , j+1)==true){

                if(ar[i][j]+1==ar[i][j+1])continue;
            }

            if(possible(i , j-1)==true){

                if(ar[i][j]+1==ar[i][j-1])continue;
            }

            if(possible(i+1 , j+1)==true){

                if(ar[i][j]+1==ar[i+1][j+1])continue;
            }

            if(possible(i+1 , j-1)==true){

                if(ar[i][j]+1==ar[i+1][j-1])continue;
            }

            if(possible(i-1 , j+1)==true){

                if(ar[i][j]+1==ar[i-1][j+1])continue;
            }

            if(possible(i-1 , j-1)==true){

                if(ar[i][j]+1==ar[i-1][j-1])continue;
            }

            return false;
        }
    }

    return true;
}

bool check()
{
    set<char>st;

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            if(ar[i][j]!='0')st.insert(ar[i][j]);
        }
    }

    if(st.size()!=9)return false;

    bool c = check2();

    return c;
}

void f(int i)
{
   // cout << i << endl;

    if(i==9){

        if(check()==true)counter++;
        return ;
    }

    int i1 = i/3, j1 = i%3;

    if(ar[i1][j1]!='0'){

        f(i+1);
    }

    else{

        for(int j = 1; j<=9; j++){

            if(taken[j]==true){continue;}

            ar[i1][j1] = j + '0';
            taken[j] = true;
            f(i+1);
            ar[i1][j1] = '0';
            taken[j] = false;
        }
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("output.txt","w",stdout);
    memset(taken , false , sizeof(taken));
    for(int i=0;i<3;i++)cin >> ar[i];

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            taken[ar[i][j]-'0'] = true;
            //cout << ar[i][j] - '0';
        }
    }

    counter = 0;

    f(0);
    cout << counter << endl;

    return 0;
}
