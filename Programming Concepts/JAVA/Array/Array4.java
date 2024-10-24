package day2;
import java.util.Arrays;

public class Array4 {
	public static void main(String[] args) {
		int a[] = {11,2,10,4,3,0};
		int b[] = {11,2,10,4,3,0};
		
		Arrays.sort(a);
		System.out.println("Sorted: " + Arrays.toString(a));
		
		boolean cmp;
		cmp = Arrays.equals(a,b);
		if(cmp)
			System.out.print("Equal");
		else
			System.out.print("Not Equal");
		
		System.out.print("\nArray Length: " + a.length);
		
		Arrays.copyOf( b, 6);
		
	}

}
