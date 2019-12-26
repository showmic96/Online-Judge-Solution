// In the name of Allah the Most Merciful

import java.util.*;
import java.math.*;
public class Main {
    
    public static void main(String arg[]){
    
        BigInteger FIB[] = new BigInteger [1010];
        FIB[0] = BigInteger.valueOf(1);
        FIB[1] = BigInteger.valueOf(1);
        
        for(int i=2;i<=1000;i++)FIB[i] = FIB[i-1].add(FIB[i-2]);
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        System.out.println(FIB[n]);
    }
} 