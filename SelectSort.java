package com.company.sort;

public class SelectSort {
    public static void normalSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int index = i;
            for (int j = i + 1; j <= arr.length - 1; j++) {
                if (arr[index] > arr[j]) {
                    index = j;
                }
            }
            if (index != i) {
                PublicApi.swap(arr, i, index);
            }
        }
    }
}
