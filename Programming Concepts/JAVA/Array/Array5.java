package day2;

public class Array5 {

	public static void main(String[] args) {
		
		int a[][] = { {1,2,3}, {4,5,6}};
		//int i, j;
		
		for(int i[]: a) {
			for(int j: i) {
				System.out.print(j + "\t");
			}
			System.out.println();
		}
	}
}
