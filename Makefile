default:
	clang++ main.cpp ./src/piece/*.cpp ./src/board/*.cpp ./src/chess/*.cpp -I./src -I./src/piece/*.cpp -I./src/board/*.cpp -I./src/chess/*.cpp -std=c++20 -I./include -L./lib -Wall -Wextra -Wpedantic -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o chess

mac:
	clang++ main.cpp ./src/piece/*.cpp ./src/board/*.cpp ./src/chess/*.cpp -I./src -I./src/piece/*.cpp -I./src/board/*.cpp -I./src/chess/*.cpp -std=c++20 -Wall -Wextra -Wpedantic -I/opt/homebrew/Cellar/raylib/5.5/include -L/opt/homebrew/Cellar/raylib/5.5/lib -lraylib -o chess

windows:
	g++ main.cpp ./src/piece/*.cpp ./src/board/*.cpp ./src/chess/*.cpp -I./src -I./src/piece/*.cpp -I./src/board/*.cpp -I./src/chess/*.cpp -s -static -Os -std=c++20 -I./include -L./lib -Wall -Iexternal -DPLATFORM_DESKTOP -lraylib -lopengl32 -lgdi32 -lwinmm -o chess.exe

browser:
	emcc -o web/index.html main.cpp ./d_modules/*.cpp flecs.o -Os -Wall ./lib/wlibraylib.a -I. -Iinclude -L. -Llib -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB
