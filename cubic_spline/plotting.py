import numpy as np
import matplotlib.pyplot as plt
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
