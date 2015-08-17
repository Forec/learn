package date_8_17;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class TestFile {
	public static void main(String[] args) {
		try {

			FileReader fr = new FileReader("test.txt");
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw =new FileWriter("testnew.txt");
			BufferedWriter bw =new BufferedWriter(fw);
			String line;
			while ((line = br.readLine()) !=null){
				bw.write(line+"\n");
			}
			bw.flush();
			bw.close();
			br.close();
			fr.close();
			fw.close();
		
		
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
