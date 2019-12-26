// In the name of Allah the Most Merciful. 

import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
       
       public static void main(String arg[]){
           
           Scanner sc = new Scanner(System.in);
           
           BigInteger fact[] = new BigInteger[105];
           
           fact[0] = new BigInteger("1");
           fact[1] = new BigInteger("1");
           
           for(int i=2;i<=100;i++){
               
               fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
           }
           
           int t = sc.nextInt();
           
           for(int i=0;i<t;i++){
               
               int n = sc.nextInt();
               
               System.out.println(fact[n]);
           }
       }
           
}