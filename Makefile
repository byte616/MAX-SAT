gen: gen.cpp	
	g++ gen.cpp -o gen.out
run:
	./gen.out
clean:
	rm *.out
