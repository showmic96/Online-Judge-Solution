#include<bits/stdc++.h>
using namespace std;

const int MAX = 100010;
bool isSquare[MAX+1];

void square_generator()
{
    for(int i=0;i<=MAX;i++)isSquare[i]=false;

    for(int i=1;i*i<=MAX;i++)isSquare[i*i]=true;

}

int main(void)
{
    int a , b;

    square_generator();

    while(cin >> a >> b){

        if(!a&&!b)break;

        int counter = 0;

        for(int i=a;i<=b;i++){

            if(isSquare[i]==true)counter++;
        }

        cout << counter << endl;
    }
    return 0;
}
