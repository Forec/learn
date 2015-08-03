package date_8_3;

import java.util.*;

public class Arraylist {
	public static void main(String [] args){
		ArrayList<Employee> staff = new ArrayList<>(10);		//initial the size first
		staff.add(new Employee("new chang","wife",11,2020,11,1));
		staff.add(new Manager("forecs","boss",1000,2015,8,3,10));
		staff.add(new Employee());
		staff.add(1,new Employee());
		staff.set(2,new Employee("hahha","test",1,2014,1,1));	// must less than size
		System.out.println(staff.size());
		staff.remove(3);
		System.out.println(staff.size());
		System.out.println((Employee)staff.get(2));
	//	staff.trimToSize();    change to stable size
		Employee after[] = new Employee[staff.size()];
		staff.toArray(after);
		for (Employee e : staff)
			System.out.println(e);
	}
}
