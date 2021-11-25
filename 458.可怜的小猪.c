int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs = 0;
    int sum = 1;

    while (sum < buckets)
    {
        sum *= (minutesToTest + minutesToDie) / minutesToDie;
        pigs++;
    }
    return pigs;
}