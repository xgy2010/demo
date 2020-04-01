package com.company.sort;

/**
 * @author xgy
 */
public class QuickSort {

    public static void normalQuickSort(int[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int l = left;
        int r = right;
        int privot = arr[left];
        while (true) {
            if (l >= r) {
                break;
            }
            while (l < r && arr[r] >= privot) {
                r--;
            }
            while (l < r && arr[l] <= privot) {
                l++;
            }
            if (l < r) {
                PublicApi.swap(arr, l, r);
            }
        }
        PublicApi.swap(arr, l, left);
        normalQuickSort(arr, left, l - 1);
        normalQuickSort(arr, l + 1, right);
    }

    public static void normalQuickSort2(int[] arr, int left, int right) {
        int l = left;
        int r = right;
        int midle = (left + right) / 2;
        int privot = arr[midle];
        while (l < r) {
            while (arr[l] < privot) {
                l++;
            }
            while (arr[r] > privot) {
                r--;
            }
            if (l >= r) {
                break;
            }
            int temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
            if (arr[l] == privot) {
                r--;
            }
            if (arr[r] == privot) {
                l++;
            }
        }
        if (l == r) {
            l++;
            r--;
        }
        if (left < r) {
            normalQuickSort2(arr, left, r);
        }
        if (right > l) {
            normalQuickSort2(arr, l, right);
        }
    }

    public static void normalQuickSort3(int[] arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int l = left;
        int r = right;
        //index随便选
        int index = (left + right) / 2;
        int pivot = arr[index];
        while (true) {
            if (l >= r) {
                break;
            }
            while (l < r && arr[r] > pivot) {
                r--;
            }
            while (l < r && arr[l] <= pivot) {
                l++;
            }
            if (l < r) {
                PublicApi.swap(arr, l, r);
            }
        }
        PublicApi.swap(arr, l, index);
        normalQuickSort3(arr, left, l - 1);
        normalQuickSort3(arr, l + 1, right);
    }

}
