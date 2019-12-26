#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[])
{
    int a;
    cin >> a;
    while(a--){

        map<char,int>ar;
        char x;
        int b;
        cin >> b;
        int ll;
        while(b--){

            cin >> x >> ll;
            ar[x]=ll;
        }

        cin >> b;
        scanf("\n");
        string br;
        long long total =0;
        while(b--){

            getline(cin,br);

            for(int j=0;j<br.size();j++){

                if(ar[br[j]]>0)total+=ar[br[j]];
            }
        }

        printf("%.2lf$\n",(double)total/100.0);
    }
    return 0;
}

