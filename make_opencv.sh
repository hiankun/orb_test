cppfile=$1
objname="${cppfile%.*}"

gcc -gdwarf-3 -O2 -Wall -o $objname $cppfile `pkg-config --cflags --libs opencv`
