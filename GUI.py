import struct
from tkinter import *
# This is gonna need to be changed to support links -> add a header for num points + list of links
fo = open("foo.pts", "rb")
# This pops the line out of the file
header = fo.readline().decode()
num_points = int(header.split()[0])
data = fo.read()
points = []
for i in range(num_points):
    points.append(struct.unpack("ii", data[i*8:i*8+8]))
print(points)

root = Tk()
window = Canvas(root, width=200, height=100)
window.pack(expand=NO, fill=BOTH)
for pt in points:
    p1 = (pt[0]+2, pt[1]+2)
    p2 = (pt[0]-2, pt[1]-2)
    window.create_oval(*p1, *p2, fill="#ff0000")

root.mainloop()
