import java.math.*;
import java.util.*;
class Main {
    static BigInteger dp[][] = new BigInteger[105][2];
    static boolean vis[][] = new boolean[105][2];
    public static int b , n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            b = sc.nextInt();
            n = sc.nextInt();
            if(b==0&&n==0)break;
            for(int i=0;i<105;i++){
                vis[i][0] = false;
                vis[i][1] = false;
            }
            System.out.println(f(0 , 0));
        }
    }
    public static BigInteger f(int i , int one){
        if(i==n)return BigInteger.ONE;
        if(vis[i][one]==true)return dp[i][one];
        vis[i][one] = true;
        BigInteger value = new BigInteger("0");
        if(i==0){
            value = value.add(f(i+1 , 1));
            BigInteger t = BigInteger.valueOf(b);
            t = t.subtract(BigInteger.valueOf(2));
            value = value.add(t.multiply(f(i+1, 0)));
        }
        else if(one==0){
            value = value.add(f(i+1 , 1));
            BigInteger t = BigInteger.valueOf(b);
            t = t.subtract(BigInteger.valueOf(1));
            value = value.add(t.multiply(f(i+1, 0)));
        }
        else if(one==1){
            value = value.add(f(i+1 , 1));
            BigInteger t = BigInteger.valueOf(b);
            t = t.subtract(BigInteger.valueOf(2));
            value = value.add(t.multiply(f(i+1, 0)));
        }
        dp[i][one] = value;
        return dp[i][one];
    }
}

