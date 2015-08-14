package data_8_13;

interface Gin<T> {
	public void say();
}

class Gen<T> implements Gin<T>{
	private String info;
	public Gen(String info){
		this.info = info;
	}
	public <T> String Test(T t){
		return "fff";
	}
	public void setInfo(String info) {
		this.info = info;
	}
	public String getInfo() {
		return info;
	}
	@Override
	public void say() {
		// TODO Auto-generated method stub
		
	}
}


public class Test {
	public static void main(String[] args) {
		Gen<String> te = new Gen<String>("testmess");
		System.out.println(te.getInfo());
	}	
}
