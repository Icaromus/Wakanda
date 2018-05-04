CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant 
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings
testField: testField.cpp
	echo ----------compiling main.cpp to create executable program main----------
	g++ -ggdb -std=c++11 testField.cpp Field.cpp Field.h -o testField
cleanField:
	echo ----------removing executable program test_stack----------
	/bin/rm testField
testhash: testHash.cpp
	echo ------------compiling test_queue.cpp to create executable program test_queue
	g++ -ggdb -std=c++11 testHash.cpp -o testHash
cleanhash:
	echo ----------removing executable program queue----------
	/bin/rm testHash
test:
	create_script test_stack.cpp test_stack
