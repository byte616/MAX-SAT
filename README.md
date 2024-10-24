# MAX-SAT with Parallel Programming

- gen.cpp: generate testcase
```
make 
make run_gen
$ input n, m, k (varables, clauses, upper bound of elements in each clause)
```
- serial.cpp: serial $\frac{1}{2}-approximation$
- pthread.cpp: parallel  $\frac{1}{2}-approximation$ with Pthread
- openmp.cpp: parallel  $\frac{1}{2}-approximation$ with OpenMP
- pthread_simd.cpp: parallel  $\frac{1}{2}-approximation$ with Pthread and SIMD (add)
- openmp_simd.cpp: parallel  $\frac{1}{2}-approximation$ with OpenMP and SIMD (add)
- pthread_SIMD.cpp: parallel  $\frac{1}{2}-approximation$ with Pthread and SIMD (add & or)
- openmp_SIMD.cpp: parallel  $\frac{1}{2}-approximation$ with OpenMP and SIMD (add & or)
