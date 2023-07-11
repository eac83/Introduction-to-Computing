set xrange[1:5]
plot 'indots.txt' u 2:3 w points lt rgb 'red', 'outdots.txt' u 2:3 w points lt rgb 'blue', 1/x with lines linetype 4