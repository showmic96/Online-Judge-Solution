// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int b , g;
    cin >> b >>  g;

    char last = 'B';

    if(b>g){
        b--;
        while(b>0||g>0){

            int temp = 1.00*ceil(b/g);

            for(int i=0;i<temp;i++){

                cout << "B" , b-- , last = 'B';
            }

            cout << "G" , g-- , last = 'G';
        }

        cout << "B" << endl;

        return 0;
    }

    if(g>b){

        g--;

        while(g>0||b>0){

            int temp = 1.00*ceil(g/b);

            for(int i=0;i<temp;i++){

                cout << "G" , g-- , last = 'G';
            }

            cout << "B" , b-- , last = 'B';
        }

        cout << "G" << endl;

        return 0;
    }

    if(b==g){

        while(b>0||g>0){

            if(last=='G')cout << "B" , b-- , last = 'B';
            else cout << "G" , g-- , last = 'G';
        }

        cout << endl;
    }

    return 0;
}
