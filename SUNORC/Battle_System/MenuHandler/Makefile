CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant 
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings
testQueue: testQueue.cpp
	echo ----------compiling main.cpp to create executable program main----------
	g++ -ggdb -std=c++11 testQueue.cpp PriorityQueue.h -o testQueue
cleanQueue:
	echo ----------removing executable program test_stack----------
	/bin/rm testQueue
testmenus: testMenus.cpp
	echo ------------compiling test_queue.cpp to create executable program test_queue
	g++ -ggdb -std=c++11 testMenus.cpp PriorityQueue.h ../Character/Character.h ../Character/Character.cpp ../Character/Point.cpp MenuHandler.h MenuHandler.cpp Field.h Field.cpp ../Menus/BattleMenu.h ../Menus/BattleMenu.cpp ../Menus/FightMenu.h ../Menus/FightMenu.cpp ../Menus/ItemMenu.h ../Menus/ItemMenu.cpp  ../Menus/TargetingMenu.h ../Menus/TargetingMenu.cpp ../Menus/MoveMenu.h ../Menus/MoveMenu.cpp ../Menus/Menu.h -o testMenus
cleanmenus:
	echo ----------removing executable program queue----------
	/bin/rm testMenus
test:
	create_script test_stack.cpp test_stack
