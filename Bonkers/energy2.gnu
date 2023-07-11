#here begins energy2.gnu

set xlabel "1 / Volume of gas"
set ylabel "Total energy of gas"
set title "Energy of gas against 1 / volume"

plot "energy.txt" u 3:2 w linespoints