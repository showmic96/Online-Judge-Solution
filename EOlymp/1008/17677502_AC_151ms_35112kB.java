import java.util.*;
import java.text.*;
import java.math.*;

public class Solution {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        String s = sc.next();

        BigInteger t1 = new BigInteger(s , n);

        String ans = t1.toString(m).toUpperCase();
        System.out.println(ans);
    }
}

