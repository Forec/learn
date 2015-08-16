package data_8_16;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class ReadByBufferdByteStream {

	public static void main(String[] args) {
		try {
			FileInputStream fis = new FileInputStream("Movie.MOV");
			FileOutputStream fos = new FileOutputStream("Movienew.MOV");
			BufferedOutputStream bos = new BufferedOutputStream(fos,100000);
			BufferedInputStream bis = new BufferedInputStream(fis,100000);
			int count = 0;
			long before  = System.currentTimeMillis();;
			byte [] input = new byte[10000];
			while(bis.read(input)!=-1){
				count++;
				bos.write(input);
			}
			bos.close();
			fos.close();
			bis.close();
			fis.close();
			System.out.println(System.currentTimeMillis()-before+"ms");
			System.out.println("读取了"+count+"次");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
