package com.company;

class Solution {
    public int romanToInt(String s) {
        int num = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == 'I') {
                num += (num >= 5 || num >= 10) ? -1 : 1;
            } else if (c == 'V') {
                num += 5;
            } else if (c == 'X') {
                num += (num >= 50 || num >= 100) ? -10 : 10;
            } else if (c == 'L') {
                num += 50;
            } else if (c == 'C') {
                num += (num >= 500 || num >= 1000) ? -100 : 100;
            } else if (c == 'D') {
                num += 500;
            } else if (c == 'M') {
                num += 1000;
            }
        }
        return num;
    }
}