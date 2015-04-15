#!/usr/bin/python

class Particle:

  def __init__(self, radius, pos, color):
    self.radius = radius
    self.pos = pos
    self.color = color

  def getRadius(self):
    return self.radius

  def getPos(self):
    return self.pos

  def getColor(self):
    return self.color
