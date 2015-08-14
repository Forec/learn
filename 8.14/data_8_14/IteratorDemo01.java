package data_8_14;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class IteratorDemo01 {
	public static void main(String []args){
		List<String> lists= new ArrayList<String>();
		lists.add("A");
		lists.add("D");
		lists.add("S");
		lists.add("A");
		lists.add("G");
		Iterator<String> iter = lists.iterator();
		while(iter.hasNext()){
			String str = iter.next();
			if ("A".equals(str)){
				iter.remove();
				continue;
			}
			System.out.println(str);
		}
		System.out.println(lists);
	}
}
