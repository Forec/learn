libs=$(find /{,usr/}lib -type f -name "libc.a" -o -name "libm.a")
for lib in $lib; do printf "$lib: "; ar t $lib | wc -l; done
