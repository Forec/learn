package data_8_16;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Buffered {
	public static void main(String[] args) {
		try {
			FileInputStream fis = new FileInputStream("Movie.MOV");
			FileOutputStream fos = new FileOutputStream("Movienew.MOV");
			long before = System.currentTimeMillis();
			byte [] input = new byte[100];
			while (fis.read(input)!=-1){
				fos.write(input);
			}
			fos.close();
			fis.close();
			System.out.println(System.currentTimeMillis()-before+"ms");
			System.out.println("输出完毕");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
