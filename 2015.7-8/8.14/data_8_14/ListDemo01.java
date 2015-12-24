package data_8_14;

import java.util.ArrayList;
import java.util.List;

public class ListDemo01 {
	public static void main(String []args){
		List<String> lists = null;
		lists = new ArrayList<String>();
		lists.add("A");
		lists.add("B");
		lists.add("A");
		for (int i = 0 ; i < lists.size() ; i++)
			System.out.println(lists.get(i));
		lists.remove(0);
		System.out.println("É¾³ıÖ®ºó");
		for(int i = 0;i < lists.size();i++)
			System.out.println(lists.get(i));
		System.out.println(lists.isEmpty());
		lists.remove(lists.indexOf("A"));
		System.out.println(lists.indexOf("A"));
	}
}
