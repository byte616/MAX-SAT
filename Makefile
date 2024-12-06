all: gen serial pthread openmp pthread_simd openmp_simd openmp_SIMD pthread_SIMD

gen: gen.cpp	
	g++ gen.cpp -o gen.out

transform: transform.cpp	
	g++ transform.cpp -o transform.out

serial: serial.cpp
	g++ -O3 serial.cpp -o serial.out

pthread:
	g++ -O3 -pthread pthread.cpp -o pthread.out 

pthread_simd:
	g++ -O3 -pthread -mavx2 pthread_simd.cpp -o pthread_simd.out 

pthread_SIMD:
	g++ -O3 -pthread -mavx2 pthread_SIMD.cpp -o pthread_SIMD.out 

openmp:
	g++ -O3 -fopenmp openmp.cpp -o openmp.out

openmp_simd:
	g++ -O3 -fopenmp -mavx2 openmp_simd.cpp -o openmp_simd.out

openmp_SIMD:
	g++ -O3 -fopenmp -mavx2 openmp_SIMD.cpp -o openmp_SIMD.out

# run
run_gen:
	./gen.out

run_serial:
	./serial.out

run_pthread:
	./pthread.out

run_pthread_simd:
	./pthread_simd.out

run_pthread_SIMD:
	./pthread_SIMD.out

run_openmp:
	./openmp.out

run_openmp_simd:
	./openmp_simd.out

run_openmp_SIMD:
	./openmp_SIMD.out

clean:
	rm *.out
	rm ./data/*.ans
