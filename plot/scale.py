import matplotlib.pyplot as plt

# Data for speedup comparison
threads = [1, 2, 3, 4, 5, 6]
openmp_speedup = [1, 4.23, 5.26, 6.10, 6.83, 7.66]
pthread_speedup = [1, 4.27, 5.41, 6.31, 7.05, 7.87]

# Create line plot for speedup comparison
plt.figure(figsize=(10, 6))
plt.rcParams.update({'font.size': 20})

# Plot for OpenMP and Pthread
plt.plot(threads, openmp_speedup, marker='o', linestyle='-', color='blue', label='OpenMP + SIMD')
plt.plot(threads, pthread_speedup, marker='o', linestyle='-', color='green', label='Pthread + SIMD')

# Labels and title
plt.xlabel('Number of Threads')
plt.ylabel('Speedup')
plt.title('Scalability between OpenMP and Pthread with SIMD')
plt.xticks(threads)
plt.legend()

plt.grid(True)
plt.tight_layout()
plt.show()

