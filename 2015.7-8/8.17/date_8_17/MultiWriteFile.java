package date_8_17;

import java.io.File;

public class MultiWriteFile {
	public static void main(String[] args) {
		File file = new File("test.txt");
		if (file.exists()){
			file.delete();
		}
		new WriteFile(file, 1).start();
		new WriteFile(file, 2).start();
		new WriteFile(file, 3).start();
		new WriteFile(file, 4).start();
		new WriteFile(file, 5).start();
		new WriteFile(file, 6).start();
		
	}
}
