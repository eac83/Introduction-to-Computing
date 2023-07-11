set term png
outfile = sprintf('gif/guitar%03.0f.png', t)
set output outfile
plot 'e.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'a.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'd.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'g.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'b.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'E2.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points,
t = t + 1
if(t<=100) reread;