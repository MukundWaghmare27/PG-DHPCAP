package day2;

public class Array2 {

	public static void main(String[] args) {
		int a[] = {11,2,10,4,3,0};
		int i, sum = 0;
		
		for(i=0; i<6; i++) {
			sum+=a[i];
			}
		System.out.println("sum of array elements is: " +sum);
	}

}
