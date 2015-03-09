#!/bin/bash

objects=$(ls *.c | sed 's/\(.*\).c/\1.o/g' | xargs)
{
cat <<EOF
CFLAGS	= -fPIC -I$JDK_HOME/include -I$JDK_HOME/include/linux
objects := ${objects}
libluajava : \$(objects)
	gcc -shared -Wl,-soname,libluajava.so.1 -o libluajava.so ${objects}
EOF
} > Makefile

gcc -MM *.c >> Makefile

{
cat <<EOF
clean:
	rm -rf ${objects}

install:
	cp -f libluajava.so ../../libs/
EOF
} >> Makefile

make && make install
