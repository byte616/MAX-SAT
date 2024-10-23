gen: gen.cpp	
	g++ gen.cpp -o gen.out

serial: serial.cpp
	g++ -O3 serial.cpp -o serial.out

pthread:
	g++ -O3 -pthread pthread.cpp -o pthread.out 

run_gen:
	./gen.out

run_serial:
	./serial.out

clean:
	rm *.out
	rm ./data/*.ans
