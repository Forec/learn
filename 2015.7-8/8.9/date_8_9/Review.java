package date_8_9;

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.Timer;

public class Review {
	public static void main(String []args){
		Employee [] staff = new Employee[3];
		staff[0] = new Employee("Forec","Engineer",2015,8,9);
		staff[1] = new Employee();
		staff[2] = new Employee("test","test",2011,1,1);
		staff[1].setID(10);
		Arrays.sort(staff);
		for (Employee e:staff){
			System.out.println(e);
		}
		ActionListener listener = new TimePrinter();
		Timer t= new Timer(1000,listener);
		t.start();
		JOptionPane.showMessageDialog(null,"Quit?");
		System.exit(0);
	}
}

class TimePrinter implements ActionListener{
	public void actionPerformed(ActionEvent event){
		Date now = new Date();
		System.out.println("At the tone , the time is " + now);
		Toolkit.getDefaultToolkit().beep();
	}
}

class Employee implements Comparable<Employee> , Cloneable{
	private static int nextid = 0;
	private int id;
	private String name;
	private String work;
	private Date hireday;
	{
		id = ++nextid;
	}
	public Employee(){
		name = "undefined";
		work = "none";
		hireday = new Date();
	}
	public Employee(String name,String work,int year,int month,int day){
		this.name = name;
		this.work = work;
		GregorianCalendar calendar = new GregorianCalendar(year,month-1,day);
		hireday = (Date)(calendar.getTime().clone());
	}
	public String getName(){
		return name;
	}
	public String getWork(){
		return work;
	}
	public int getID(){
		return id;
	}
	public void setID(int id){
		this.id = id;
	}
	public Date getHireday(){
		return (Date)(hireday.clone());
	}
	public int compareTo(Employee other){
		return id - other.id;
	}
/*	public void actionPerformed(ActionEvent event){
		Date now= new Date();
		System.out.println("At the tone , the time is "+now);
		Toolkit.getDefaultToolkit().beep();
	}*/
	@Override public String toString(){
		return name +", ID"+id+ ", is a "+ work + ", hired at "+hireday;
	}
	@Override public boolean equals(Object otherObject){
		if (this == otherObject)
			return true;
		if (otherObject == null)
			return false;
		if (getClass() != otherObject.getClass())
			return false;
		Employee other = (Employee)otherObject;
		return name.equals(other.name)  && id == other.id ;
	}
	@Override public Employee clone() throws CloneNotSupportedException{
		Employee cloned = (Employee)super.clone();
		cloned.hireday = (Date)hireday.clone();
		return cloned;
	}
}