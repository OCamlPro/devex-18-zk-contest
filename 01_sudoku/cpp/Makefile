all: sudoku.cpp
	./build.sh

sudoku.cpp sudoku.hpp: ../ml/freeton_sudoku_generator/sudoku_generator
	../ml/freeton_sudoku_generator/sudoku_generator 3


../ml/freeton_sudoku_generator/sudoku_generator: ../ml/freeton_sudoku_generator/src/sudoku_generator/*.ml
	cd ../ml/freeton_sudoku_generator; drom build
