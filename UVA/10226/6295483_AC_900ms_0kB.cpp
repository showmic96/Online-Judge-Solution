#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    map<string,int>mai;
    set<string>name;
    set<string>::iterator it;
    scanf("\n");
    int d=0;
    while(a--){
        if(d==1)cout << endl;
        d=1;
        name.clear();mai.clear();
        
        string ar;
        int j=0;
        while(getline(cin , ar)){
            if(ar=="")break;
            j++;
            name.insert(ar);
            mai[ar]++;
        }
        for(it=name.begin();it!=name.end();it++){
            cout << *it;
            printf(" %.4lf\n",100.00*(double)mai[*it]/j);
        }
        
        



    }
    return 0;
}
