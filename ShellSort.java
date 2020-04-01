package com.company.sort;

public class ShellSort {
    /**
     * 交换法
     */
    public static void normalShellSort(int[] arr) {
        //第1次
//        for (int i = 5; i < arr.length; i++) {
//            for (int j = i - 5; j >= 0; j -= 5) {
//                if (arr[j+5]<arr[j]){
//                    PublicApi.swap(arr,j+5,j);
//                }else {
//                    break;
//                }
//            }
//        }
        //第2次
//        for (int i = 2; i < arr.length; i++) {
//            for (int j = i - 2; j >= 0; j -= 2) {
//                if (arr[j+2]<arr[j]){
//                    PublicApi.swap(arr,j+5,j);
//                }else {
//                    break;
//                }
//            }
//        }
        for (int gap = arr.length / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < arr.length; i++) {
                for (int j = i - gap; j >= 0; j -= gap) {
                    if (arr[j + gap] < arr[j]) {
                        PublicApi.swap(arr, j + gap, j);
                    } else {
                        break;
                    }
                }
            }
        }
    }

    /**
     * 移动法
     */
    public static void normalShellSort1(int[] arr) {
        for (int gap = arr.length / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < arr.length; i++) {
                int temp = arr[i];
                int j;
                for (j = i - gap; j >= 0; j -= gap) {
                    if (arr[j + gap] < arr[j]) {
                        arr[j + gap] = arr[j];
                    } else {
                        break;
                    }
                }
                if (j + gap != i) {
                    arr[j + gap] = temp;
                }
            }
        }
    }
}
