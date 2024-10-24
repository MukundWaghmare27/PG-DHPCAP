package day2;

public class Array {

	public static void main(String[] args) {
		int a[] = {11,2,10,4,3,0}, i, j, n=6;
		int temp;
		
		for ( i=0; i<n-1; i++) {
			for (j=0; j<n-i-1; j++) {
				if(a[j]>a[j+1]) {
					temp = a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		
		//System.out.print('Sorted Array:');
		for(i=0; i<6; i++) {
			System.out.println(a[i]);
		}
		
	}

}
