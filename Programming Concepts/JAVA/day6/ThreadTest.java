package day6;

class A implements Runnable{
	public void run() {
		for(int i=1;i<6;i++) {
			System.out.println("class A");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
class B implements Runnable{
	public void run() {
		for(int i=1;i<6;i++) {
			System.out.println("class B");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
public class ThreadTest {

	public static void main(String[] args) {
		A a1 = new A();
		B b1 = new B();
		
		Thread t1 = new Thread(a1);
		Thread t2 = new Thread(b1);
		
		t1.run();
		t2.run();
		
	}
	
}
