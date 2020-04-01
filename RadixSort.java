package com.company.sort;

public class RadixSort {
    public static void normalRadixSort(int[] arr) {
        //10个桶
        int[][] backet = new int[10][arr.length];
        //记录每个桶里有效的数字的个数
        int[] backetElementCounts = new int[10];
        //开始获得每位数，然后放到对应的桶里面
        //然后再将其取出来放到arr里面。

        //round表示轮数，最大的位数有几位数就有几轮
        int tempIndex = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[tempIndex] < arr[i]) {
                tempIndex = i;
            }
        }
        int maxLength = (arr[tempIndex] + "").length();
        for (int round = 0, dev = 1; round < maxLength; round++, dev *= 10) {
            //第一轮--------------------
            for (int i = 0; i < arr.length; i++) {
                int index = arr[i] / dev % 10;
                backet[index][backetElementCounts[index]] = arr[i];
                backetElementCounts[index]++;
            }
            int k = 0;
            for (int i = 0; i < backet.length; i++) {
                if (backetElementCounts[i] != 0) {
                    for (int j = 0; j < backetElementCounts[i]; j++) {
                        arr[k] = backet[i][j];
                        k++;
                    }
                }
                backetElementCounts[i] = 0;
            }
            //第一轮-----------------
        }

    }
}
