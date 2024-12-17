# MAX-SAT with Parallel Programming

- gen.cpp: generate testcase (testcase will generate in directory ``data/``)
```
make gen 
make run_gen
$ input n, m, k (varables, clauses, upper bound of elements in each clause)
```

- run MAX-SAT solver
```
make solver_name
make run_solver_name

e.g., run pthread_simd
make pthread_simd
make run_pthread_simd
```

- MAX-Sat solver option:
  - serial.cpp: serial $\frac{1}{2}-approximation$
  - pthread.cpp: parallel  $\frac{1}{2}-approximation$ with Pthread
  - openmp.cpp: parallel  $\frac{1}{2}-approximation$ with OpenMP
  - pthread_simd.cpp: parallel  $\frac{1}{2}-approximation$ with Pthread and SIMD (add)
  - openmp_simd.cpp: parallel  $\frac{1}{2}-approximation$ with OpenMP and SIMD (add)
  - pthread_SIMD.cpp: parallel  $\frac{1}{2}-approximation$ with Pthread and SIMD (add & or)
  - openmp_SIMD.cpp: parallel  $\frac{1}{2}-approximation$ with OpenMP and SIMD (add & or)


- plot experiment result (in `plot/`)

```
python3 experiment.py 
```

- experiment type:
  - compare_serial.py: compare serial and parallel
  - SIMD.py: ablation study
  - scale.py: multi-threading scalability
  - plot_SOTA.py: compare with heuristic   
