all:
	@g++ -o AG src/AG.cpp src/TicTacToe.cpp src/Neuron.cpp src/Helper.cpp src/Wizard.cpp src/ConfMatrix.cpp src/Ind.cpp src/Ram.cpp -I./include -g -Wall -lm
run:
	@./AG
frun:
	@valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all ./AG
	