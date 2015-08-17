package date_8_17;

import java.io.File;
import java.io.IOException;

import org.apache.commons.io.FileUtils;

public class TestApacheIO {
	public static void main(String[] args) {
		File file = new File("test.txt");
		File file2 = new File("testNew.txt");
		try {
//			String input = FileUtils.readFileToString(file,"UTF-8");
//			System.out.println(input);
			FileUtils.copyFile(file, file2);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
