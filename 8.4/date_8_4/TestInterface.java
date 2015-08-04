package date_8_4;

import java.util.*;

public class TestInterface {
	public static void main(String[]args){
		Employee[] staff = new Employee[3];
		GregorianCalendar d = new GregorianCalendar(2016,2,3);
		staff[0] = new Employee("forec","test",10,new Date());
		staff[1] = new Employee("chang","leanr",11,d.getTime());
		staff[2] = new Employee();
		staff[2].setID(1);
		
		Arrays.sort(staff);
		
		for (Employee e : staff)
			System.out.println(e);
		
		System.out.println(staff[1] instanceof Comparable); //是否实现comparable接口
	}
}
