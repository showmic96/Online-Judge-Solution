// In the name of Allah the Most Merciful. 

import java.util.Scanner;
import java.math.BigInteger;

class Main
{

    public static void main(String args[]){
        
       
        Scanner sc = new Scanner(System.in);
        
            
        int n , m;
        while(sc.hasNext()){
            
            BigInteger a = sc.nextBigInteger();
            m = sc.nextInt();
            
            if(a.compareTo(BigInteger.ZERO)==0&&m==0)break;
            a = a.pow(m);
            System.out.println(a);
        }
    }        
}