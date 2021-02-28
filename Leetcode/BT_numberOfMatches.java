public class numberOfMatches {
    class Solution {
        public int numberOfMatches(int n) {
            int count = 0;
            while (n > 1) {
                count += n / 2;
                n = n / 2 + n % 2;
            }
            return count;
        }
    }
    // BackTracking
    class Solution2{
        int answer;
        public void BT(int n,int matches){
            if(n==1){
                answer = matches;
                return;
            }

            matches += n/2;
            BT((n+1)/2,matches);

        }
        public int numberOfMatches(int n) {
            BT(n,0);
            return answer;
        }
    }


}
