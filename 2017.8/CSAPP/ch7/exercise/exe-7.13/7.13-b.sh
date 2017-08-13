gcc -O2 main.c swap.c -o t1
gcc -O2 -g main.c swap.c -o t2
readelf -a t1 > t1.elf
readelf -a t2 > t2.elf
diff -u t1.elf t2.elf
