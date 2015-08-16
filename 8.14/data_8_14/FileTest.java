package data_8_14;

import java.io.File;
import java.io.IOException;

public class FileTest {
	public static void main(String []args){
		File file = new File("bin/hello.txt");
		try {
			file.createNewFile();
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		File nameto = new File("newname.txt");
		file.renameTo(nameto);
		if(file.exists()){
			file.delete();
			System.out.println("文件已经被删除");
		}
		else {
			System.out.println("文件不存在");
			try {
				file.createNewFile();
				System.out.println("文件已经成功创建");
			} catch (IOException e) {
				e.printStackTrace();
				System.out.println("文件不能创建");
			}
		}
	}
}
