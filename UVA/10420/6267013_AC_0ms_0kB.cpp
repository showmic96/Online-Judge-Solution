#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    map<string,int>country;

    string name[3000];
    int a;
    string ar , cr;
    cin >> a;
    int d=0;
    while(a--){
        char br[100];
        scanf("\n");
        getline(cin , ar);
        int j = 0 , k = 0;
        while(ar[j]==' ')j++;
        //cout << ar[j];
        while(ar[j]!=' '&&ar[j]!='\0'){br[k]=ar[j];j++;k++;}
        br[k]='\0';
        //cout << br[1] << endl;;
        country[br]++;
        name[d]=br;d++;
    }

    sort(name,name+d);
    for(int a=0;a<d;a++){
    if(a==0)cout << name[a] << " " << country[name[a]] << endl;
    if(a!=0)if(name[a-1]!=name[a])cout << name[a] << " " << country[name[a]] << endl;
    }
    return 0;


}
