package date_8_18;

import java.io.FileNotFoundException;
import java.io.FileReader;

import com.google.gson.JsonArray;
import com.google.gson.JsonIOException;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import com.google.gson.JsonSyntaxException;

public class ReadJson {

	public static void main(String[] args) {
		JsonParser parser = new JsonParser();
		try {
			JsonObject object = (JsonObject) parser.parse(new FileReader("test.json"));
			System.out.println("cat = " + object.get("cat").getAsString());
			System.out.println("pop = " + object.get("pop").getAsString());
			JsonArray array = object.get("languages").getAsJsonArray();
			for ( int i = 0 ; i < array.size();i++){
				System.out.println("----------");
				JsonObject subobj = array.get(i).getAsJsonObject();
				System.out.println("id="+ subobj.get("id").getAsInt());
				System.out.println("name="+ subobj.get("name").getAsString());
				System.out.println("ide="+ subobj.get("ide").getAsString());
			}
		} catch (JsonIOException e) {
			e.printStackTrace();
		} catch (JsonSyntaxException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
