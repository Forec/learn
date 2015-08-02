/**
 * define class Employee
 */

package date_8_2;

import java.util.*;

class Employee {
	private String name;
	private double salary;
	private Date hireday;
	public Employee(){
		name = "undefine";
		salary = 0 ;
		hireday = new Date();
	}
	public Employee(String n,double s,int year,int month,int day){
		name = n;
		salary = s;
		GregorianCalendar calendar = new GregorianCalendar(year,month-1,day);
		hireday = calendar.getTime();
	}
	public String getName(){
		return name;
	}
	public double getSalary(){
		return salary;
	}
	public Date getHireDay(){
		return hireday;	//   This method is not safe
	//	return hireday.clone();
	}
	public void raiseSalary(double byPercent){
		salary +=( salary * byPercent/100 );
	}
}
