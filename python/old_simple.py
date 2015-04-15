#!/bin/python

import Tkinter as tk

counter = 0
def counter_label(label):
  global counter
  label.config(text=str(counter))

def count():
  global counter
  counter += 1
  label.config(text=str(counter))

def motion(event):
  print("Mouse position: (%s %s)" % (event.x, event.y))
  return


root = tk.Tk()
root.title("Lets count... Bitch")
label = tk.Label(root, fg="red")
label.pack()
counter_label(label)
button = tk.Button(root, text="blah", width=40, command=count) #root.destroy)
button.pack()

msg = tk.Message(root, text="blah blah blah", width=100)
msg.config(bg="lightgreen")
msg.bind('<B1-Motion>', motion)
msg.pack()

root.mainloop()

