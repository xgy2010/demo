package com.company.sort;

public class InsertSort {
    /**
     *交换法
     */
    public static void normalInsertSortway1(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int temp = arr[i + 1];
            for (int j = i; j >= 0; j--) {
                if (temp < arr[j]) {
                    PublicApi.swap(arr, j, j + 1);
                } else {
                    break;
                }
            }

        }
    }

    /**
     *移动法
     */
    public static void normalInsertSortway2(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int temp = arr[i + 1];
            int j;
            for (j = i; j >= 0; j--) {
                if (temp < arr[j]) {
                    arr[j + 1] = arr[j];
                } else {
                    break;
                }
            }
            if (j != i) {
                arr[j + 1] = temp;
            }

        }
    }

    public static void normalInsertSortway3(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            int j;
            for (j = i-1; j >= 0; j--) {
                if (temp < arr[j]) {
                    arr[j + 1] = arr[j];
                } else {
                    break;
                }
            }
            if (j != i) {
                arr[j + 1] = temp;
            }

        }
    }
}
