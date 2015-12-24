/**
 * @author Forec_
 * used to test array in java
 */

package date_8_1;

import java.util.Arrays;

public class TestArray {
	public static void main(String [] args){
		int[] a = new int[100];
		for ( int i = 0 ; i< 100 ; i++)	
			a[i] = 100 - i;
		System.out.println(a.length);
		Arrays.sort(a);
		System.out.println(Arrays.binarySearch(a,11));
	//	int []c = a;
	//	c[3] = 1;
		for (int element : a)
			System.out.print(element+" ");
		System.out.println();
		int [] b = Arrays.copyOf(a, 2*a.length);
		Arrays.sort(b);
		for (int element:b)
			System.out.print(element+" ");
		System.out.println();
		int n = 100;
		int []ans = new int[4];
		for (int k = 0; k < 4 ; k++){
			int r =(int)(Math.random()*n);
			ans[k] = a[r];
			a[r] = a[n-1];
			n--;
		}
		for ( int element : ans)
			System.out.println(element);
	}
}
