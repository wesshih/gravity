#!/bin/python

from operator import *

G = 1 #6.67/100000000

# calculates the force on p1 by p2
def calcGravForce((m1, pos1), (m2, pos2)):
  coeff = (G * m1 * m2)/(pow(calcRadius(pos1, pos2),2))
  return map(lambda a: a*coeff, map(lambda a,b: b-a, pos1, pos2))

# finds radius between two points p1 and p2
def calcRadius(pos1, pos2):
  return pow(sum(map(lambda a,b: pow(b-a,2), pos1, pos2)), 0.5)

def calcAccel(f, m):
  return [fi/m for fi in f]

def calcVel(a, v_old):
  return map(add, a, v_old)



#part_1 = (1, (0, 0, 0))
#part_2 = (1, (1, 0, 0))
#print("part_1 (%s, %s, %s) " % (part_1[1]))
#print("part_2 (%s, %s, %s) " % (part_2[1]))
#radius = calcRadius(part_1[1], part_2[1])
#print "radius: %s" % radius
#force = calcGravForce(part_1, part_2)
#print "force: %s" % force
#accel = calcAccel(force, 2)
#print "accel: %s" % accel
#vel = [0, 0, 0]
#print "vel: %s" % vel
#vel = calcVel(accel, vel)
#print "vel: %s" % vel
