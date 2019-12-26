// In the name of Allah the Most Merciful. 

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.*;
import java.math.*;
import java.util.*;

class Main {
    
    
    public static BigInteger dp[][] = new BigInteger[2005][2];
    
    
    public static BigInteger f(int n , int z){
        
        //System.out.println(n + " " + z);
        
        if(n<=1){
            
            return BigInteger.valueOf(0);
        }
        
        if(dp[n][z].compareTo(BigInteger.valueOf(-1))!=0)return dp[n][z];

        BigInteger value = new BigInteger("0");

        if(z==0&&n>=6)value = value.add(BigInteger.valueOf(1));
        else if(n-6>=0)value = value.add(f(n-6 , 1)).add(BigInteger.valueOf(1));

        if(n-2>=0)value = value.add(f(n-2 , 1)).add(BigInteger.valueOf(1));

        if(n-5>=0)value = value.add(f(n-5 , 1)).add(BigInteger.valueOf(1));

        if(n-5>=0)value = value.add(f(n-5 , 1)).add(BigInteger.valueOf(1));

        if(n-4>=0)value = value.add(f(n-4 , 1)).add(BigInteger.valueOf(1));

        if(n-5>=0)value = value.add(f(n-5 , 1)).add(BigInteger.valueOf(1));

        if(n-6>=0)value = value.add(f(n-6 , 1)).add(BigInteger.valueOf(1));

        if(n-3>=0)value = value.add(f(n-3 , 1)).add(BigInteger.valueOf(1));

        if(n-7>=0)value = value.add(f(n-7 , 1)).add(BigInteger.valueOf(1));

        if(n-6>=0)value = value.add(f(n-6 , 1)).add(BigInteger.valueOf(1));

        return dp[n][z] = value;
        
    }
    
    public static void main(String args[] ) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        
        for(int i=0;i<2005;i++){
            
            for(int j=0;j<2;j++)dp[i][j] = BigInteger.valueOf(-1);
        }
        
        while(sc.hasNext()){
            
            int n = sc.nextInt();
            
            System.out.println(f(n , 0));
            
        }
        
    }
}
