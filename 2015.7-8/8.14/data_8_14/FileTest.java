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
			System.out.println("�ļ��Ѿ���ɾ��");
		}
		else {
			System.out.println("�ļ�������");
			try {
				file.createNewFile();
				System.out.println("�ļ��Ѿ��ɹ�����");
			} catch (IOException e) {
				e.printStackTrace();
				System.out.println("�ļ����ܴ���");
			}
		}
	}
}
