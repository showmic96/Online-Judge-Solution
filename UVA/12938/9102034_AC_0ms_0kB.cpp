// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string ar;
bool taken[11];
int counter = 0;
int input;

void f(int i , int value , int c)
{

    if(i==4){

        if(c==1&&value>=1000){
            if(value==input)return;
            double v = value;
            //cout << value << " " << sqrt(value) << " " << sqrt(v) << endl;
            if((double)sqrt(v)==(int)sqrt(value))counter++;
        }

        return ;
    }

    f(i+1, value*10+(ar[i]-'0') , c);

    for(int j=0;j<=9;j++){

        if(taken[j]==false){

            taken[j] = true;

            if(c==0)f(i+1, value*10+j , 1);

            taken[j] = false;
        }
    }
}

int main(void)
{
    int t , c = 0;
    cin >> t;
    while(t--){

        cin >> ar;
        memset(taken , false , sizeof(taken));
        counter = 0;
        stringstream ss (ar);
        ss >> input;
        f(0 , 0 , 0);
        printf("Case %d: ",++c);
        cout << counter << endl;
    }
    return 0;
}
