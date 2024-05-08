import numpy as np

def get_points():
    n = int(input("Input number of points: "))

    x = np.zeros(n)
    y = np.zeros(n)

    print("Enter the points:")
    for i in range(n):
        x[i], y[i] = map(float, input().split())

    return x, y
