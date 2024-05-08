from input_operations import get_points
from cubic_spline import compute_cubic_spline_coefficients
from plotting import plot_cubic_spline

def main():
    x, y = get_points()
    a, b, c, d = compute_cubic_spline_coefficients(x, y)
    plot_cubic_spline(x, y, a, b, c, d)

if __name__ == "__main__":
    main()
