for (int k = 0; k<n; k++) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (d[i][j]>d[i][k]+d[k][j]) {
                d[i][j] = d[i][k]+d[k][j];
            }
        }
    }
}