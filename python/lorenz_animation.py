#!/bin/python

import numpy as np
from scipy import integrate

from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.colors import cnames
from matplotlib import animation


N_trajectories = 20


def lorentz_deriv((x, y, z), t0, sigma=10, beta=8/3, rho=28.0):
  """Compute the time-derivative of a Lorenz system. """
  return [sigma * (y - x), x * (rho - z) - y, x * y - beta * z]



np.random.seed(1)
x0 = -15 + 30 * np.random.random((N_trajectories, 3))

t = np.linspace(0, 4, 1000)
x_t = np.asarray([integrate.odeint(lorentz_deriv, x0i, t) for x0i in x0])

fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1], projection='3d')
ax.axis('off')

colors = plt.cm.jet(np.linspace(0, 1, N_trajectories))

lines = sum([ax.plot([], [], [], '-', c=c) for c in colors], [])
pts = sum([ax.plot([], [], [], 'o', c=c) for c in colors], [])


ax.set_xlim((-25, 25))
ax.set_ylim((-35, 35))
ax.set_zlim((5, 55))

ax.view_init(30, 0)

def init():
  for line, pt in zip(lines, pts):
    line.set_data([], [])
    line.set_3d_properties([])

    pt.set_data([], [])
    pt.set_3d_properties([])
  return lines + pts

def animate(i):
  i = (2 * i) % x_t.shape[1]

  for line, pt, xi in zip(lines, pts, x_t):
    x, y, z = xi[:i].T
    line.set_data(x, y)
    line.set_3d_properties(z)

    pt.set_data(x[-1:], y[-1:])
    pt.set_3d_properties(z[-1:])

  ax.view_init(30, 0.3 * i)
  fig.canvas.draw()
  return lines + pts


anim = animation.FuncAnimation(fig, animate, init_func=init, frames=500, interval=30, blit=True)

plt.show()
