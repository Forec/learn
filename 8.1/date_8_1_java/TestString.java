/**
 * @author Forec_
 * used to test string class and StringBuilder
 */

package date_8_1;

import java.lang.StringBuilder;
import java.lang.String;

public class TestString {
	public static void main(String[] args){
		String name = "gotit";
		System.out.println(name);
		System.out.println(name.substring(1,3));
		System.out.println("fill"+name.substring(2,4));
		String name2 = "gots";
		System.out.println(name2.equals(name.substring(0,3)+"s"));
		
		String voidstring = "";
		if (voidstring.length()==0){
			System.out.println("equal to void string");
		}
		String testnull = null;
		if (testnull == null){
			System.out.println("undefined is null");
		}
		String news = voidstring;
		news = news + "hel÷–o string";
		int cpcount = news.codePointCount(0,news.length());
		char first = news.charAt(0);
		char end = news.charAt(3);
		System.out.println(cpcount +  " " +news.length()  +" " +first + " " + end);
		int i;
		for ( i = 0 ; i < cpcount ; i++){
			int cp = news.codePointAt(i);
			if (Character.isSupplementaryCodePoint(cp))
				i+=2;
			else 
				i++;
		}
		System.out.println();	
		StringBuilder builder = new StringBuilder();
		builder.append('t');
		builder.append("est");
		builder.append(builder.length());
		builder.setCharAt(1,'a');
		builder.delete(0, 1);
		String tests = builder.toString();
		System.out.println(tests);
	}
}
