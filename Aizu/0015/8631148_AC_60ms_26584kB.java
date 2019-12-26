// In the name of Allah the Most Merciful. 

import java.io.*;
import java.util.*;
import java.math.*;

class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        for(int i=0;i<t;i++){
            
            BigInteger a , b;
            
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            
            a=a.add(b);
            
            if(a.toString().length()>80)System.out.println("overflow");
            else System.out.println(a);
        }
    }
}