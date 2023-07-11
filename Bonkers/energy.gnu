#here begins energy.gnu

set xlabel "Volume of gas"
set ylabel "Total energy of gas"
set title "Energy of gas against volume"

plot "energy.txt" u 1:2 w linespoints