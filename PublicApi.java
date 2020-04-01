package com.company.sort;

/**
 * @author Administrator
 */
public class PublicApi {
    public static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
