#A MAKE FILE.

Make: Clear Dependencies Compile

Compile:
	@echo "Compiling proyect..."
	g++ -std=gnu++11 src/PermAlias.cpp -o bin/PermAlias

Dependencies:
	@echo "Building dependencies..."
	@mkdir bin

Clear:
	@echo "Cleaning proyect..."
	@rm -f -r bin
	@rm -f src/*.cpp~
	@rm -f src/*.cpp#
	@rm -f *~
