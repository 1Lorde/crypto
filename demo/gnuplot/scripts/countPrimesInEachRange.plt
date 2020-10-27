# Scale font and line width (dpi) by changing the size! It will always display stretched.
set terminal svg size 400,300 enhanced fname 'arial'  fsize 8 butt solid
set output '../plots/countPrimesInEachRange.svg'

# Key means label...
set key inside top left
set xlabel 'Range of naturals numbers'
set ylabel 'Amount of primes'
set title 'Amount of primes in different ranges'
set boxwidth 30
set style fill solid
plot "../data/countPrimesInEachRange.dat" using 1:2:xtic(1) title "primes amount" with boxes