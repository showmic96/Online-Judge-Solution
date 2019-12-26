// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<string>v , dir;
char x[1005];
string ar;

void print(int i , string temp)
{
    if(i==ar.size()){

        int si = temp.size();
        for(int i1=0;i1<si;i1++)printf("%c",temp[i1]);
        printf("\n");

        return ;
    }
    if(ar[i]=='0'){

        for(int i1=0;i1<10;i1++){
            string t = temp;

            t+='0'+i1;
            print(i+1 , t);
        }
    }
    else{

        int si = v.size();
        for(int i1=0;i1<si;i1++){

            int s = v[i1].size();
            string t = temp;

            for(int j1=0;j1<s;j1++)t+=v[i1][j1];

            print(i+1 , t);
        }
    }
}

int main(void)
{
    int n , m;
    while(scanf("%d",&n)==1){

        v.clear();

        for(int i=0;i<n;i++){

            scanf("%s",&x);
            string temp(x);
            v.push_back(temp);
        }

        scanf("%d",&m);

        printf("--\n");

        for(int i=0;i<m;i++){

            scanf("%s",&x);
            string temp(x);
            ar = x;
            print(0 , "");
        }
    }
    return 0;
}
