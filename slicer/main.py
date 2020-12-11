from pather import Pather

pather = Pather('pattern2.svg')

all_xs, all_ys = pather.getPaths()

f = open('out.gcode', 'w')
f.write('H0\n')
f.write('G0 Z4200\n')

for xs, ys in zip(all_xs, all_ys):
	for x, y in zip(xs, ys):
		x = (x-600) * 6 - 500
		y = y*5
		f.write('G0 X{} Y{} U{}\n'.format(int(x), int(y), int(y)))

f.write('G0 X0 Y0 U0')
