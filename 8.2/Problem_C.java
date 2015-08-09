/**
 * @author Forec_
 * write to help chang
 */

package date_8_2;
import java.util.*;
public class Problem_C {
	public static void main(String []args){
		Scanner in = new Scanner(System.in);
		int n;
		n = in.nextInt();
		int[] data = new int[n];
		for ( int i = 0 ; i < n ; i++)
			data[i] = in.nextInt();
		in.close();
		Arrays.sort(data);
		int count = 1 , ans = data[0];
		int pre = 0 ;
		for ( int i = 1 ; i < n ; i ++){
			if (data[i] != data[i-1]){
				if ( count < i - pre ){
					count = i - pre;
					ans = data[pre];
				}
				pre = i;
			}
		}
		System.out.println(ans);
	}
}