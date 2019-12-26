// In the name of Allah the Most Merciful

//package lab.assignment;
import java.util.*;
import java.math.*;
public class Main {
    
    public static void main(String arg[]){
    
        BigInteger FIB[] = new BigInteger [101000] , f = BigInteger.valueOf(10);
        FIB[0] = BigInteger.valueOf(1);
        FIB[1] = BigInteger.valueOf(1);
        int ans[] = new int[50010];

        int d = 1;
        for(int i=2;;i++){FIB[i] = FIB[i-1].add(FIB[i-2]);if(FIB[i].compareTo(f)>0){ans[d]=i;d++;f=f.multiply(BigInteger.valueOf(10));}if(d>5010)break;}
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int i=0;i<t;i++){
            
            int n = sc.nextInt();
            System.out.println(ans[n-1] + 1);
        }
        
    }
} 