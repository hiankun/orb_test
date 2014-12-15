cppfile=$1
objname="${cppfile%.*}"

g++ -gdwarf-3 -O2 -Wall -o $objname $cppfile `pkg-config --cflags --libs opencv`
