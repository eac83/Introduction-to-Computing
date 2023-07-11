#here begins plot.gnu

set term png
outfile = sprintf('gif/bonkers%03.0f.png', t)
set output outfile
set title sprintf("Time =  %0.02f s", t*dt)
set xrange [-10:10]
set yrange [-10:10]
set key off

plot for [c=1:N] 'balls.txt'  every ::t::t using 3*c-2:3*c-1:3*c w circles fill solid, 'wall.txt' every ::2*t::2*t+1 u 1:2 w linespoints
t = t + 1
if(t<T/dt) reread;