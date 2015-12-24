package data_8_14;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

import javax.swing.event.TreeExpansionEvent;

public class ListDemo02 {

	public static void main(String[] args) {
		Set<String> s = null;
		s= new TreeSet<String>();
		s.add("A");
		s.add("D");
		s.add("E");
		s.add("C");
		s.add("S");
		System.out.println(s);
	}

}
