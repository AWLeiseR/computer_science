
public class Programa implements Runnable {
	
	private int id;
	
	public void setId(int id) {
		this.id = id;
	}

	@Override
	public void run() {
		
		for (int i = 0; i < 100; i++){
			System.out.println("programa: "+this.id+" valor: "+i);
		}
	}

}
