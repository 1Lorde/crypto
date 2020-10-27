# Scale font and line width (dpi) by changing the size! It will always display stretched.
set terminal svg size 400,300 enhanced fname 'arial' fsize 8 butt solid
set output '../plots/primeNumberChanceInEachRange.svg'

# Key means label...
set key inside top right
set xlabel 'Range of natural numbers'
set ylabel 'Chance of prime number'
set title 'Probability of prime number in range'
plot  "../data/primeNumberChanceInEachRange.dat" using 1:2 title 'chance' with lines