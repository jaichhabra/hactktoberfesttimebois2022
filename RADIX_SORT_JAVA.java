package com.sorting;

import java.util.Arrays;

public class radix_sort {
    public static void main(String[] args) {
        int []arr={3,2,1,0};
//finding max element
        int max=0;
        for(int i=0;i<arr.length;i++){
            max=Math.max(arr[i],max);
        }
 // passing values of exponent|| 1  10  100  1000 .....
        int exponent=1;
        while(max>0){
           CountSort(arr,exponent);
        exponent=exponent*10;
           max=max/10;
        }
        System.out.println(Arrays.toString(arr));
    }
    private static void CountSort(int[] arr,int exponent) {

        //creating an array of size 10 since all exist or lie  between 0 to 9
        int [] appear=new int[10];

        //storing no. of count each value appeared
        for(int i=0;i<arr.length;i++){
            //storing according to base value
            int index=arr[i]/exponent %10;
            appear[index]+=1;
        }
        //finding cumulative frequency
        for(int j=0;j<appear.length-1;j++){
            appear[j+1]+=appear[j];
        }

        //creating a temporary array to sort value according to values stored in appeared array
        int [] temp=new int[arr.length];

        for(int i=arr.length-1;i>=0;i--){
            // running from backward to maintain its stableness
            temp[appear[arr[i]/exponent%10] -1]=arr[i];
            appear[arr[i]/exponent%10]-=1;
        }

        for(int i=0;i< arr.length;i++){
            arr[i]=temp[i];
        }
    }
}
