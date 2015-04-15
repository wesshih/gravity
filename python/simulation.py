#!/bin/python

from gravity import *
import numpy as np
from operator import *

from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.colors import cnames
from matplotlib import animation

numP = 2
numT = 50

ps = []
for i in range(numP):
  # a particle is (mass, radius, position(x,y,z), velocity(x,y,z))
  ps.append((1, 1, (i, 0, 0), (0, i, 0)))

x_t = [tuple(ps)]

# 'Phases' of simulation
# move each particle according to its velocity
# for each particle, calc the gravForce for every other particle
# for each particle, calculate the accel and update velocity for next

def moveParticles(ps):
  for i in range(len(ps)):
    #ps[i][2] = map(add, ps[i][2], ps[i][3])
    ps[i] = tuple(tuple(map(add, ps[i][2], ps[i][3])) if j==2 else ps[i][j] for j in range(len(ps[i])))

def updateVelocity(ps):
  for i in range(len(ps)):
    for j in range(len(ps)):
      if (i == j): continue
      f = calcGravForce((ps[i][0], ps[i][2]), (ps[j][0], ps[j][2]))
      a = calcAccel(f, ps[i][0])
      #ps[i][3] = calcVel(a, ps[i][3])
      ps[i] = tuple(tuple(calcVel(a, ps[i][3])) if k==3 else ps[i][k] for k in range(len(ps[i])))

def simForT(ps, t, x_t):
  for ti in range(t):
    print "simulating for time %s" % ti
    moveParticles(ps)
    updateVelocity(ps)
    x_t.append(tuple(ps))


#print x_t
simForT(ps, numT, x_t)
#print x_t
print "done"

fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1], projection='3d')
ax.axis('off')

colors = plt.cm.jet(np.linspace(0,1,numP))


ax.set_xlim((-10, 10))
ax.set_ylim((-10, 10))
ax.set_zlim((1, 20))
ax.view_init(30,0)


theta = np.linspace(-4 * np.pi, 4*np.pi, 100)
z = np.linspace(-2, 2, 100)
r = z**2 + 1
x = r * np.sin(theta)
y = r * np.cos(theta)
line = ax.plot(x, y, z, label='parametric curve')

#lines = sum([ax.plot([], [], [], '-', c=c) for c in colors], [])

#def init():
#  #for line in lines:
#  line_a.set_data([], [])
#  line_a.set_3d_properties([])
#  return line_a

#def animate(i):
#  #x(t) = 3t+1
#  #y(t) = 0.25t-1
#  #z(t) = -t+0.5
#  #for line in lines:
#  x = i/10
#  y = i/10
#  z = i/10
#  line_a.set_data(x, y)
#  line_a.set_3d_properties(z)
#  ax.view_init(30, 0.5 * i)
#  fig.canvas.draw()
#  return line_a

#anim = animation.FuncAnimation(fig, animate, init_func=init, frames=500, interval=15, blit=True)

plt.show()
