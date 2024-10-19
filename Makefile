gen: gen.cpp	
	g++ gen.cpp -o gen.out

serial: serial.cpp
	g++ serial.cpp -o serial.out

run_gen:
	./gen.out

run_serial:
	./serial.out

clean:
	rm *.out
