public static int minTaps(int[] bulbs) {
//        dp[i] is the minimum number of bulbs require enlightening locations [0, i].
//        Initialize dp[i] with max = n + 1
//        dp[0] = [0] as we need no bulb to enlighten anything.
//        Find the leftmost point of street enlightened with bulb i.
//        Find the rightmost point of street to enlightened with bulb i.
//        We can enlighten [left, right] with one bulb,
//        and enlighten [0, left - 1] with dp[left - 1] bulbs.
        int n = bulbs.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            // we can only enlighten if bulbs[i]>=0
            if (bulbs[i] >= 0) {
                int leftMostPointOfStreetEnlightenedByCurrentBulb = 1 + Math.max(i - bulbs[i], 0); // +1 since dp.length = n+1
                int rightMostPointOfStreetEnlightenedByCurrentBulb = 1 + Math.min(i + bulbs[i], n - 1);
                for (int j = leftMostPointOfStreetEnlightenedByCurrentBulb; j <= rightMostPointOfStreetEnlightenedByCurrentBulb; ++j) {
                    dp[j] = Math.min(dp[j], dp[Math.max(0, i - bulbs[i])] + 1);
                }
            }
        }
        return dp[n] < n + 1 ? dp[n] : -1;
    }
