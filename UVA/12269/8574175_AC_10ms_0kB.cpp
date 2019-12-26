// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1010;

struct myStruct{

    double start , end;

}data1[MAX+9] , data2[MAX+9];

bool cmp(struct myStruct A , struct myStruct B)
{

    return A.start < B.start;
}

int main(void)
{
    int n , m;
    double w;

    while(cin >> n >> m >> w){

        if(!n&&!m&&!w)break;

        w/=2;

        bool check = true;

        for(int i=0;i<n;i++){

            double in;
            cin>> in;

            data1[i].start = in - w;
            data1[i].end = in + w;
        }

        for(int i=0;i<m;i++){

            double in;
            cin>> in;

            data2[i].start = in - w;
            data2[i].end = in + w;
        }

        sort(data1 , data1+n , cmp);
        sort(data2 , data2+m , cmp);

        double current = 0;

        for(int i=0;i<n;i++){

            if(data1[i].start > current){
                break;
            }

            current = data1[i].end;
        }

        if(current<75)check = false;
        current = 0;

        for(int i=0;i<m;i++){

            if(data2[i].start > current){
                //cout << current << " " << data2[i].start << endl;
                break;
            }

            current = max(current,data2[i].end);
        }

        //cout << current << endl;

        if(check==false)cout << "NO" << endl;
        else if(current < 100) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
