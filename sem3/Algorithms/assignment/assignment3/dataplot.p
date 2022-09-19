   set autoscale                        # scale axes automatically
      unset log                              # remove any log-scaling
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
	  set tics font "Helvetica,10"
      set title "Calculate Time Comlexity"
      set xlabel "Input Size"
      set ylabel "Time Taken"
      #set key 0.01,100
      #set label "Yield Point" at 0.003,260
      #set arrow from 0.0028,250 to 0.003,280
      set xr [0:108000]
      set yr [0.00000:100]
        plot  "quicksort1000.txt" using 1:2 title 'Best' with linespoints, \
            "quicksort10000.txt" using 1:2 title 'Average'  with linespoints,\
            "quicksort100000.txt" using 1:2 title 'Worst'  with linespoints