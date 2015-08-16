package data_8_14;

import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class MapDemo01 {

	public static void main(String[] args) {
		Map<String,String> map = new TreeMap<String,String>();
		map.put("key1","forec");
		map.put("key2","test");
		map.put("key31","cccccccc");
		map.put("key4","github");
		map.put("key5","gitcafe");
		map.put("key6","shit");
		String str = map.get("key2");
		System.out.println(str);
		if (map.containsKey("key3"))
			System.out.println("key存在");
		else {
			System.out.println("keybuncunzia");
		}
		if (map.containsValue("forec"))
			System.out.println("forec存在");
		else {
			System.out.println("forec不存在");
		}
//		Set<String> s= map.keySet();
//		Iterator<String> iter = s.iterator();
//		while(iter.hasNext()){
//			System.out.println(iter.next());
//		}
		Collection<String> cl = map.values();
		Iterator<String> i = cl.iterator();
		while(i.hasNext())
			System.out.println(i.next());
	}

}
