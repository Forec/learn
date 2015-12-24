package date_8_3;

import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.Scanner;
import java.io.IOException;

public class FileStream {
	public static void main(String[] args)throws IOException{
		System.out.println(System.getProperty("user.dir"));
		Scanner input = new Scanner(Paths.get("test.txt"));
		String words = input.nextLine();
		System.out.println(words);
		PrintWriter out = new PrintWriter("outfile.txt");
		out.println(words);
		input.close();
		out.close();
	}
}
