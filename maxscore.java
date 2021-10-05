class Solution{
    public long maximumScore(int N, int cost1, int cost2, int values[], int labels[]){
        HashMap<Integer, Long> dp= new HashMap<Integer,Long>();
        
        for (int i = 0; i < N; i++) {
            dp.put(labels[i], (long)-1e16);
        }
        dp.put(0,(long)0);
        int firstMax = 0, secondMax = 0;

        for (int i = 0; i < N; i++) {
            dp.put(labels[i], Math.max(dp.get(labels[i]) + (long)cost2 * (long)values[i], dp.get(labels[i])));

            if (labels[i] != firstMax) {
                dp.put(labels[i], Math.max(dp.get(labels[i]), dp.get(firstMax) + (long)values[i] * (long)cost1));
            } else {
                dp.put(labels[i],Math.max(dp.get(labels[i]), dp.get(secondMax) + (long)values[i] * (long)cost1));
            }

            if (labels[i] != firstMax) {
                if (dp.get(labels[i]) > dp.get(firstMax)) {
                    secondMax = firstMax;
                    firstMax = labels[i];
                } else if (dp.get(labels[i]) > dp.get(secondMax)) {
                    secondMax = labels[i];
                }
            }
        }
        return dp.get(firstMax);
    }
}
