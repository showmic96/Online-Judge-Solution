// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    scanf("\n");

    for(int i=0;i<t;i++){

        string ar;
        getline(cin , ar);

        if(i!=0)cout << endl;

        int p , n;
        //cin >> p >> n;

        stringstream ss(ar);

        ss >> p;
        ss >> n;

        set<int>st[p+10];
        bool visited[p+10];
        memset(visited , false ,sizeof(visited));

        while(getline(cin , ar)){

            if(ar=="")break;

            int t1 , t2;

            stringstream s(ar);
            s >> t1;
            s >> t2;

            st[t1].insert(t2);
        }

        int counter = 0;

        for(int i=1;i<=p;i++){

            if(visited[i]==false){
                
                counter++;
                
                for(int j=i+1;j<=p;j++){
                    
                    if(st[i]==st[j]){
                        visited[j] = true;
                    }
                }
            }
        }

        cout << counter << endl;
    }
    return 0;
}
