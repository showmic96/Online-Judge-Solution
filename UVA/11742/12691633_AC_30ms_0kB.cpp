// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct data{

    int a , b , c;
    data(int _a , int _b , int _c){

        a = _a;
        b = _b;
        c = _c;
    }
};

vector<data>v;
int n , m , counter , ar[10];
bool taken[10];

void f(int i)
{
    if(i==n){

        bool check = true;

        for(int j=0;j<m;j++){

            int t1 = v[j].a;
            int t2 = v[j].b;
            int t3 = v[j].c;

            for(int i1=0;i1<n;i1++){

                if(ar[i1]==t1){

                    for(int j1=0;j1<n;j1++){

                        if(ar[j1]==t2){

                            if(t3<0){

                                if(abs(i1-j1)<-t3)check = false;
                            }

                            else{

                                if(abs(i1-j1)>t3)check = false;
                            }
                        }
                    }
                }
            }
        }

        if(check)counter++;
        return ;
    }

    for(int j=0;j<n;j++){

        if(taken[j]==false){

            taken[j] = true;
            ar[i] = j;

            f(i+1);

            taken[j] = false;
            ar[i] = 0;
        }
    }
}

int main(void)
{
    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;
        v.clear();

        for(int i=0;i<m;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            v.push_back(data(in1 , in2 , in3));
        }

        memset(ar , 0 , sizeof(ar));
        memset(taken , false , sizeof(taken));

        counter = 0;

        f(0);

        printf("%d\n",counter);
    }
    return 0;
}
