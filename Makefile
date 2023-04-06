default:
	clang++ main.cpp -std=c++20 -I./include -L./lib -Wall -Wextra -Wpedantic -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o chess

browser:
	emcc -o web/index.html main.cpp ./d_modules/*.cpp flecs.o -Os -Wall ./lib/wlibraylib.a -I. -Iinclude -L. -Llib -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB

flecs:
	clang flecs.c -I. -c -o flecs.o
