#Here begins lfplot.gnu

set term png
outfile = sprintf('gif/planets%03.0f.png', t)
set output outfile
set title "Time: " . t . " Weeks"
set xlabel "Distance / m"
set ylabel "Distance / m"
plot 'leapfrog.txt' every ::1::(t+1) u 1:2 w lines title "2.0 AU", 'leapfrog.txt' every ::1::(t+1) u 3:4 w lines title "1.8 AU", 'leapfrog.txt' every ::1::(t+1) u 5:6 w lines title "1.6 AU", 'leapfrog.txt' every ::1::(t+1) u 7:8 w lines title "1.4 AU", 'leapfrog.txt' every ::1::(t+1) u 9:10 w lines title "1.2 AU"

t = t + 1
if(t<100) reread;