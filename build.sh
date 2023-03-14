#!/bin/sh

compile()
{
	#for file in *.c; do
	#	gcc -c -ggdb -O0 "$file"
	#done

	gcc -c -ggdb -O0 ./*.c
}

make_library()
{
	#for object in *.o; do
	#	ar r libjts.a $object
	#done

	ar r libjts.a ./*.o
}


if [ $# -eq 0 ]; then
	compile && make_library
	exit
fi

if [ "$1" = "d" ] && [ $# -ge 1 ]; then
	rm -f ./*.o ./*.a
	exit
fi
