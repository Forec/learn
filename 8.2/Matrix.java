/**
 * @author Forec_
 */

package date_8_2;

public class Matrix {
	public static void main(String[]args){
		final int NMAX = 10;
		int [][]odds = new int [NMAX+1][];
		for (int n=0;n<=NMAX;n++)
			odds[n] = new int[n+1];
		for (int n= 0; n<odds.length;n++)
			for (int i = 0 ; i < odds[n].length ; i++ ){
				int lotteryOdds = 1;
				for (int j = 1; j <=i;j++)
					lotteryOdds = lotteryOdds*(n-j+1)/j;
				odds[n][i] = lotteryOdds;
			}
		for (int[] rows:odds){
			for (int odd:rows)
				System.out.printf("%4d",odd);
			System.out.println();
		}
	}
}
