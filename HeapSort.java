package com.company.sort;

/**
 * @author Administrator
 */
public class HeapSort {
    public static void heapSort(int[] arr) {
        for (int i = arr.length / 2 - 1; i >= 0; i--) {
            downHeap(arr, i, arr.length);
        }

        for (int j = arr.length - 1; j > 0; j--) {
            int temp = arr[j];
            arr[j] = arr[0];
            arr[0] = temp;
            downHeap(arr, 0, j);
        }
    }

    /**
     * @param arr    要调整成大顶堆的数组
     * @param i      要下沉的非叶子节点
     * @param length 堆有效长度
     */
    public static void downHeap(int[] arr, int i, int length) {
        int temp = arr[i];
        for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
            if (k + 1 < length && arr[k] < arr[k + 1]) {
                k++;
            }
            if (arr[k] > temp) {
                arr[i] = arr[k];
                i = k;
            } else {
                break;
            }
        }
        arr[i] = temp;
    }
}
