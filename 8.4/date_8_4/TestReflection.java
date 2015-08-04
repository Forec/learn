/**
 * @author Forec_
 * used to test reflection
 */

package date_8_4;

import java.lang.Class;
//import java.lang.reflect.Constructor;

public class TestReflection {
	public static void main(String[]args){
		Employee e = new Employee();
		Class cl = e.getClass();  // String classname="date_8_4.Employee";
								//  	Class cl = Class.forName(className);
		System.out.println(cl.getName() + " " + e.getName());
	//	Class c2 = Employee.class;
//		Object newo = c2.newInstance();     Wrong?
	}
}
