package date_8_19;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;


public class TestHttpGet {

	public static void main(String[] args) {
		new ReadByGet().start();
	}
	static class ReadByGet extends Thread{
		@Override
		public void run() {
			try {
				
				
				URL url = new URL("http://fanyi.youdao.com/openapi.do?keyfrom=testhttp22222&key=1198006312&type=data&doctype=xml&version=1.1&q=welcome");
				URLConnection connection = url.openConnection();
				InputStream is = connection.getInputStream();
				InputStreamReader isr = new InputStreamReader(is);
				BufferedReader br= new BufferedReader(isr);
				
				StringBuilder builder = new StringBuilder();
				String line;
				while ((line = br.readLine())!=null){
					builder.append(line);
				}
				br.close();
				isr.close();
				is.close();
				
				System.out.println(builder.toString());
				
				
				
			} catch (MalformedURLException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		}
	}
}
