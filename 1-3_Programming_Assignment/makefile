all: compile clean run
compile: Collection_test.o Jeans_test.o Stress_ball_test.o Jeans.o Stress_ball.o
	g++ -o test Collection_test.o Jeans_test.o Stress_ball_test.o Jeans.o Stress_ball.o

clean:
	rm -f ./*.o

run: test
	./test