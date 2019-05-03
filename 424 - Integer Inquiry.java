package UVA_BIGINTEGER_PROBLEM;
import java.math.BigInteger;
import java.util.Scanner;

/*
 * Accepted 
 * 
 */
public class Integer_Inquiry_424 { // accepted 
	public static void main (String[] args){
		Scanner sc=new Scanner (System.in);
		BigInteger sum=BigInteger.ZERO;
		BigInteger x = null;
		while (true){
			x=sc.nextBigInteger();
			if (x.compareTo(BigInteger.ZERO)==0) break;
			sum=sum.add(x);
		}
		System.out.println(sum);
		sc.close();
	}
}
