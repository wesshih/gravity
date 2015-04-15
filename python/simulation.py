#!/bin/python

from gravity import *
import numpy as np
from operator import *


numP = 10
numT = 1000

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

#print ps
#moveParticles(ps)
#print ps
#updateVelocity(ps)
#print ps
#print x_t
