int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (!duration) return 0;

    int res = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++) {
        if (timeSeries[i] + duration - 1 < timeSeries[i + 1]) res += duration;
        else {
            res += timeSeries[i + 1] - timeSeries[i];
        }
    }

    return res + duration;
}