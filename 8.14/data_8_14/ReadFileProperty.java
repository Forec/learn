package data_8_14;

import java.io.File;

public class ReadFileProperty {
	public static void main(String[] args) {
		File file = new File("text.txt");
		System.out.println(file.exists());
		System.out.println(file.getName());
		System.out.println(file.getAbsolutePath());
		System.out.println(file.getParent());
		System.out.println(file.getPath());
		System.out.println(new File(file.getAbsolutePath()).getParent());
		file.setWritable(true);
		if(file.setReadable(false))
			System.out.println("yes");
		else
			System.out.println("can;t");
		if (file.setReadOnly())
			System.out.println("ok");
	}
}
