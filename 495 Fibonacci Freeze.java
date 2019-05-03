package UVA_BIGINTEGER_PROBLEM;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Badhan Sen
 * 495 Fibonacci Freeze
 * Accepted
 */

class Fibonacci_Freeze {
    
    
    public static void main(String[] args){
        BigInteger[] fib=new BigInteger [5001];
        fib[0]=BigInteger.ZERO;
        fib[1]=BigInteger.ONE;
        int n;
        for (int i=2; i<=5000; i++){
            fib[i]=fib[i-1].add(fib[i-2]);
        }
        Scanner sc=new Scanner (System.in);

        while (sc.hasNext()){
            n=sc.nextInt();
            
            System.out.println("The Fibonacci number for "+ n + " is "+ fib[n].toString());
        }
        sc.close();
    }

   

    
}
