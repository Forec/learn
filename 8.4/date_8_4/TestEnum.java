/**
 * @author Forec_
 * used to test enum class
 */

package date_8_4;

import java.util.Scanner;

public class TestEnum {
	public static void main(String[]args){
		Size[]values = Size.values();
		for (Size e:values)
			System.out.print(e.toString() + " ");
		System.out.println();
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a size:(SMALL,MEDIUM,LARGE,EXTRA_LARGE)");
		String input = in.next().toUpperCase();
		Size size = Enum.valueOf(Size.class , input);
		System.out.println("size= "+size );
		System.out.println("abbreviation = " +size.getAbbreviation());
		if (size == Size.EXTRA_LARGE)
			System.out.println("You paid attention to be...");
		in.close();
	}
}

enum Size{
	SMALL("S") , MEDIUM("M") , LARGE("L") , EXTRA_LARGE("XL");
	private Size(String abbreviation){		//定义上行的构造器
		this.abbreviation = abbreviation;			//缩写
	}
	private String abbreviation;
	public String getAbbreviation(){
		return abbreviation;
	}
}
