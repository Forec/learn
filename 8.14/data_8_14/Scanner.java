package data_8_14;

import java.io.File;

public class Scanner {
	public static void main(String[] args) {
		printFiles(new File("F:/Develop/Hack"),0);
	}
	public static void printFiles(File dir,int length){
		if (dir.isDirectory()){
			File [] next = dir.listFiles();
			for (File E: next){
				if (E.isFile()){
					for (int i= 0; i< length;i++)
						System.out.print("  ");
						System.out.print("|__");
					System.out.println(E.getName());
				}
				else {
					for (int i= 0; i< length;i++)
						System.out.print("  ");
					System.out.print("|__");
					System.out.println(E.getName());
					printFiles(E,length+1);
				}
			}				
		}
		else {
			System.out.println(dir+"is not a directory");
		}
	}
}
