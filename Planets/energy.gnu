#Here begins energy.gnu

set title "Plot of planet energy against time"
set xlabel "Time / week"
set ylabel "Energy / J"
plot 'eeng.txt' u 1:2 w lines title '2.0 AU', 'eeng.txt' u 3:4 w lines title '1.8 AU', 'eeng.txt' u 5:6 w lines title '1.6 AU', 'eeng.txt' u 7:8 w lines title '1.4 AU', 'eeng.txt' u 9:10 w lines title '1.2 AU'
