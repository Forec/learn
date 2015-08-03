/**
 * @author Forec_
 * test abstract class
 */

package date_8_3;

import java.util.*;

abstract class Person {
	private String name;
	public Person(){
		name = "undefined";
	}
	public Person(String n){
		name = n;
	}
	public abstract String getDescription();
	public String toString(){
		return "name: "+name +","+ getDescription();
	}
	public String getName(){
		return name;
	}
	public int hashCode(){
		return name.hashCode()%10001;
	}
	public boolean equals(Object otherObject){
		if (this==otherObject)
			return true;
		if (otherObject == null)
			return false;
		if (getClass()!=otherObject.getClass())
			return false;
		Person other = (Person)otherObject;
		return name.equals(other.name);
	}
}

class Student extends Person{
	private String major;
	public Student(){
		super();
		major = "none";
	}
	public Student(String n,String major){
		super(n);
		this.major = major;
	}
	public String getDescription(){
		return "a student manjor in "+major;
	}
	@Override public int hashCode(){
		return (7*super.hashCode()+13*major.hashCode())%10001;
	}
	@Override public boolean equals(Object otherObject){
		if (!super.equals(otherObject))
			return false;
		Student other = (Student)otherObject;
		return major.equals(other.major);
	}
}

class Employee extends Person{
	private String work;
	private int salary;
	private Date hireday;
	public Employee(){
		super();
		work = "none";
		salary = 0;
		hireday = new Date();
	}
	public Employee(String n,String work,int salary,int year,int month,int day){
		super(n);
		this.work = work;
		this.salary = salary;
		GregorianCalendar calendar = new GregorianCalendar(year,month-1,day);
		hireday = calendar.getTime();
	}
	public Date getHireday(){
		return hireday;
	}
	public int getSalary(){
		return salary;
	}
	public String getDescription(){
		return "his job is "+work+", his salary is "+salary+", his hireday is "+hireday;
	}
	@Override public int hashCode(){
		return (super.hashCode()*5 + work.hashCode()*11 + salary + hireday.hashCode()*17)%10001;
	}
	@Override public boolean equals(Object otherObject){
		if (!super.equals(otherObject))
			return false;
		Employee other = (Employee)otherObject;
		if (other.hireday == null && hireday !=null || hireday == null && other.hireday!=null)
			return false;
		if (other.hireday == null && hireday == null)
			return true;
		if (!hireday.equals(other.hireday))
			return false;
		return work.equals(other.work) && salary==other.salary;
	}
}

class Manager extends Employee{
	private int bonus;
	public Manager(){
		super();
		bonus = 0;
	}
	public Manager(String name,String work,int salary,int year,int month,int day,int bonus){
		super(name,work,salary,year,month,day);
		this.bonus = bonus;
	}
	public void setBonus(int bonus){
		this.bonus = bonus;
	}
	@Override public int hashCode(){
		return (super.hashCode() *11 + bonus*23)%10001;
	}
	@Override public int getSalary(){
		return super.getSalary() + bonus;
	}
	@Override public String getDescription(){
		return super.getDescription()+",bonus = "+bonus;
	}
	@Override public boolean equals(Object otherObject){
		if (!super.equals(otherObject))
			return false;
		Manager other = (Manager)otherObject;
		return other.bonus == bonus;
	}
}