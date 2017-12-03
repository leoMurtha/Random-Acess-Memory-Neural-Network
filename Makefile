all:
	@g++ -o main src/main.cpp src/Neuron.cpp src/Helper.cpp src/Wizard.cpp src/ConfMatrix.cpp src/Ram.cpp -I./include -g -Wall -lm
run:
	@./main
frun:
	@valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all ./main
	