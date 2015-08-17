package date_8_17;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class WriteFile extends Thread{
	File file;
	int block;
	int L = 100;
	private RandomAccessFile raf;
	public WriteFile(File f,int b){
		this.file = f;
		this.block =b;
	}
	public void  run(){
		try {
			raf = new RandomAccessFile(file, "rw");
			raf.seek((block-1)*L);
			raf.writeUTF(new String("中国热".getBytes("UTF-8")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
