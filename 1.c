#include <stdio.h>

struct LinearMode1 {
    double omega;
    double b;
};

struct LinearMode1 lm = {0, 0};

void fit(double x_train[], double y_train[]) {
    if (x_train[0]!= x_train[1]) {
        lm.omega = (y_train[0] - y_train[1]) / (x_train[0] - x_train[1]);
        lm.b = y_train[0] - x_train[0] * lm.omega;
    } else {
        printf("Error: Division by zero. Cannot fit the data.\n");
    }
    return;
}

double predict(double x_train) {
    double y_train;
    y_train = lm.omega * x_train + lm.b;
    return y_train;
}

int main() {
    double X[2], Y[2];
    printf("Input x1 y1 x2 y2: ");
    if (scanf("%lf %lf %lf %lf", &X[0], &Y[0], &X[1], &Y[1])!= 4) {
        printf("Invalid input. Please enter four valid numbers.\n");
        return 1;
    }
    fit(X, Y);
    printf("Training result: omega=%lf, b=%lf\n\n", lm.omega, lm.b);
    double x;
    printf("Input x: ");
    if (scanf("%lf", &x)!= 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }
    double y = predict(x);
    printf("Predict result: x=%.2lf 平米, y=%.2lf 万元\n", x, y);
    return 0;
}