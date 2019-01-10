from numpy import *
from matplotlib.pyplot import *
from scipy.integrate import *

SizeOfHalfKpoint = 10

HalfWaveFunction = np.zeros((SizeOfHalfKpoint, 2))


def ode1(y, t):
    return -2*y


time = linspace(1, 10, 100)
sol1 = odeint(ode1, 1, time)

plot(time, sol1)
show()

print(time)