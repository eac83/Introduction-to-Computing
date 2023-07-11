f(N) = sqrt((log(2)*(1-log(2))/N))
set xrange[1:2130]
plot log(2)+f(x) with lines linetype 5, log(2)-f(x) with lines linetype 5, 'tmpfile.txt' u 5:6 with linespoints