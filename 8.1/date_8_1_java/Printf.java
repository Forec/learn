/**
 * @author Forec_
 * used to test format output and file stream
 */

package date_8_1;

import java.util.*;
import java.io.PrintWriter;
import java.nio.file.Paths;
import java.io.IOException;

public class Printf {
	public static void main(String []args)throws IOException{
		float x = - 10000 / 3 ;
		String dir = System.getProperty("user.dir");		// IDE Æô¶¯Â·¾¶
		System.out.println(dir);
		System.out.printf("%(.3f-dfadfa\n",x);
		System.out.printf("%1$s %2$tB %<td, %<tY\n","today: ",new Date());
		Scanner in = new Scanner(Paths.get("test_input.txt"));
		PrintWriter out = new PrintWriter("test_output.txt");
		int t = in.nextInt();
		out.println(t);
		in.close();
		out.close();
	}
}
