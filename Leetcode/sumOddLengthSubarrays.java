package com.company;


public class Solution {
    public static int sumOddLengthSubarrays(int[] arr) {
        int res = 0;
        int len = arr.length;

        for( int i =0 ; i < ((len+1)/2) ; i++){
            for(int j =0 ; j < (len-2*i) ; j++){
                for( int k =0 ; k < (2*i+1) ; k++){
                    res += arr[j+k];
                }
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int[] arr = new int[] {1,4,2,5,3};
        sumOddLengthSubarrays(arr);
    }
}

// Another solution

//public class Solution {
//    public int SumOddLengthSubarrays(int[] arr) {
//        int res = 0;
//        var len = arr.Length;
//        for (int i = 0; i < len; ++i) {
//            res += ((i + 1) * (len - i) + 1) / 2 * arr[i];
//        }
//        return res;
//    }
//}