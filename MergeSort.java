package com.company.sort;

public class MergeSort {
    public static void normalMergeSort(int[] arr, int left, int right, int[] temp) {
        if (left < right) {
            int midle = (left + right) / 2;
            normalMergeSort(arr, left, midle, temp);
            normalMergeSort(arr, midle + 1, right, temp);
            merge(arr, left, midle, right, temp);
        }
    }

    public static void merge(int[] arr, int left, int mid, int right, int[] temp) {
        int l = left;
        int m = mid + 1;
        int r = right;
        int index = 0;
        while (true) {
            if (l > mid || m > right) {
                break;
            }
            if (arr[l] < arr[m]) {
                temp[index] = arr[l];
                l++;
                index++;
            } else {
                temp[index] = arr[m];
                m++;
                index++;
            }
        }
        if (l > mid) {
            System.arraycopy(arr, m, temp, index, r - m + 1);
        }
        if (m > right) {
            System.arraycopy(arr, l, temp, index, mid - l + 1);
        }
        System.arraycopy(temp, 0, arr, left, right - left + 1);
    }
}
