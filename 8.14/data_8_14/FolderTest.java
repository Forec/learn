package data_8_14;

import java.io.File;

public class FolderTest {
	public static void main(String []args){
		File folder = new File("my new Folder");
		if(folder.mkdir())
			System.out.println("�������");
		else
			if (folder.exists()){
				folder.delete();
				System.out.println("�ļ���ɾ�����");
			}
	}
}
