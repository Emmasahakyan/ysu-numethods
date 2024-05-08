import numpy as np
import matplotlib.pyplot as plt

def lotka_volterra(t, state, a, b, c, d):
    x, y = state
    dxdt = a*x - b*x*y
    dydt = -c*y + d*x*y
    return np.array([dxdt, dydt])

def runge_kutta(f, t0, tf, y0, h, *args):
    t_values = np.arange(t0, tf + h, h)
    y_values = np.zeros((len(t_values), len(y0)))
    y_values[0] = y0
    for i in range(1, len(t_values)):
        k1 = h * f(t_values[i-1], y_values[i-1], *args)
        k2 = h * f(t_values[i-1] + h/2, y_values[i-1] + k1/2, *args)
        k3 = h * f(t_values[i-1] + h/2, y_values[i-1] + k2/2, *args)
        k4 = h * f(t_values[i-1] + h, y_values[i-1] + k3, *args)
        y_values[i] = y_values[i-1] + (k1 + 2*k2 + 2*k3 + k4) / 6
    return t_values, y_values

# Predefined parameters
a = 0.05
b = 0.003
c = 0.02
d = 0.002

# Initial conditions
x0 = 100  # Initial population of rabbits(for example)
y0 = 20   # Initial population of foxes(for example)
state0 = np.array([x0, y0])

# Time parameters
t0 = 0
tf = 1000
h = 0.1 

t_values, y_values = runge_kutta(lotka_volterra, t0, tf, state0, h, a, b, c, d)

# Plot the results
plt.figure(figsize=(10, 6))
plt.plot(t_values, y_values[:, 0], label='Rabbits')
plt.plot(t_values, y_values[:, 1], label='Foxes')
plt.xlabel('Time')
plt.ylabel('Population')
plt.title('Predator-Prey Dynamics (Lotka-Volterra Model)')
plt.legend()
plt.grid(True)
plt.show()
