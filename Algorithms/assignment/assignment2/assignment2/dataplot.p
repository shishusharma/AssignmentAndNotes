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
      set xr [1000:200000]
      set yr [0.000000:50]
      plot  "mergeSort.txt" using 1:2 title 'MergeSort' with linespoints