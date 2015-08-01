/**
 * @author Forec_
 * used to test big integer
 */

package date_8_1;

import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.*;

public class BigDigital {
	public static void main(String[] args){
		BigInteger a = BigInteger.valueOf(1);
		int n;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		for (int i = 1; i <= n ;i++)
			a = a.multiply(BigInteger.valueOf(i));
		String ans = a.toString();
		while (ans.length()>60){
			System.out.println(ans.substring(0,59));
			ans = ans.substring(60,ans.length()-1);
		}
		if (ans.length()!=0)
			System.out.println(ans);
		
		int r = in.nextInt();
		in.close();
		BigDecimal b = BigDecimal.valueOf(1);
		for (int i = 1; i <= r ; i++){
			b = b.multiply(BigDecimal.valueOf(n-i+1)).divide(BigDecimal.valueOf(i));
		}
		ans = b.toString();
		while (ans.length()>=60){
			System.out.println(ans.substring(0, 59));
			ans = ans.substring(60, ans.length()-1);
		}
		if ( ans.length()!=0)
			System.out.println(ans);
	}
}
