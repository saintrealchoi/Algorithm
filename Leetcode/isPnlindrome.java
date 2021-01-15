package com.company;


class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 )
            return false;
        else{
            int y =x;
            int div = 0;
            int tmp = 0;

            while( y> 0 ){
                div = y % 10;
                y /= 10;
                tmp = tmp*10 + div;
            }
            if(tmp == x)
                return true;
            else
                return false;
        }
    }
}