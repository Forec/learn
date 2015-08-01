/**
 * @author Forec_
 * used to test iostream
 */

package date_8_1;

import java.util.*;
import java.lang.StringBuilder;
import java.lang.String;
import java.lang.System;
//import java.io.Console;
//import java.io.*;

public class Iostream {
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		String name = in.next();
		int id = in.nextInt();
		int money = in.nextInt();
		String position = in.nextLine();
		StringBuilder builde = new StringBuilder();
		builde.append(name);
		builde.append(' ');
		builde.append(id+" "+money);
		builde.append(" "+position);
		System.out.println(builde.toString());
		System.out.println(money);
		System.out.println("----"+position+"----");
/**		Console cons = System.console();
		if (cons==null)
			System.out.println("error!");
		String username = cons.readLine("user name:");
		char [] passwd = cons.readPassword("Password:");
		System.out.println(username);
		System.out.println(passwd);   */
		//   Console can't be used in IDE like eclipse
		in.close();
	}
}
