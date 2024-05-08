import numpy as np
import matplotlib.pyplot as plt

def main():
    n = int(input("Input number of points: "))

    x = np.zeros(n)
    y = np.zeros(n)

    print("Enter the points:")
    for i in range(n):
        x[i], y[i] = map(float, input().split())

    # Compute coefficients for cubic spline
    a, b, c, d = compute_cubic_spline_coefficients(x, y)

    # Plot the cubic spline
    plot_cubic_spline(x, y, a, b, c, d)

def compute_cubic_spline_coefficients(x, y):
    n = len(x)
    h = np.diff(x)
    alpha = np.zeros(n)
    for i in range(1, n - 1):
        alpha[i] = (3 / h[i]) * (y[i + 1] - y[i]) - (3 / h[i - 1]) * (y[i] - y[i - 1])
    l = np.zeros(n)
    mu = np.zeros(n)
    z = np.zeros(n)
    l[0] = 1
    mu[0] = 0
    z[0] = 0
    for i in range(1, n - 1):
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1]
        mu[i] = h[i] / l[i]
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i]
    l[n - 1] = 1
    z[n - 1] = 0
    c = np.zeros(n)
    b = np.zeros(n)
    d = np.zeros(n)
    for j in range(n - 2, -1, -1):
        c[j] = z[j] - mu[j] * c[j + 1]
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3
        d[j] = (c[j + 1] - c[j]) / (3 * h[j])
    a = y[:-1]
    return a, b, c, d

def plot_cubic_spline(x, y, a, b, c, d):
    plt.figure()
    for i in range(len(x) - 1):
        xs = np.linspace(x[i], x[i + 1], 100)
        ys = a[i] + b[i] * (xs - x[i]) + c[i] * (xs - x[i]) ** 2 + d[i] * (xs - x[i]) ** 3
        plt.plot(xs, ys)
    plt.scatter(x, y, color='red', label='Data Points')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Cubic Spline Interpolation')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
