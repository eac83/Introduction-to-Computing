#Here begins lfangmom.gnu

set title "Plot of planet angular momentum against time"
set xlabel "Time / week"
set ylabel "Angular momentum / kg km^2 s^-1"
plot 'lang.txt' u 1:2 w lines title '2.0 AU', 'lang.txt' u 3:4 w lines title '1.8 AU', 'lang.txt' u 5:6 w lines title '1.6 AU', 'lang.txt' u 7:8 w lines title '1.4 AU', 'lang.txt' u 9:10 w lines title '1.2 AU'
