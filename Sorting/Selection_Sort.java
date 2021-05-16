package Sorting;

public class Selection_Sort {
	public static void main(String[] args) {
		int[] a = {4,3,6,7,0,8,1,2,5,9};
		int min_idx,i,j;
		for(i=0;i<9;i++) {
			min_idx=i;
			for(j=i+1;j<10;j++) {
				if(a[j]<a[min_idx])
					min_idx=j;
			}
			int temp=a[i];
			a[i]=a[min_idx];
			a[min_idx]=temp;
	}
		for(int x:a) {
			System.out.print(x+" ");
		}
 }

}
