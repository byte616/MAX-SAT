import matplotlib.pyplot as plt

# Data for speedup comparison
threads = [1, 2, 3, 4, 5, 6]
openmp_speedup = [1, 1.83, 2.43, 2.71, 3.21, 3.69]
pthread_speedup = [1, 1.84, 2.51, 2.80, 3.30, 3.74]

# Create line plot for speedup comparison
plt.figure(figsize=(10, 6))

# Plot for OpenMP and Pthread
plt.plot(threads, openmp_speedup, marker='o', linestyle='-', color='blue', label='OpenMP + SIMD')
plt.plot(threads, pthread_speedup, marker='o', linestyle='-', color='green', label='Pthread + SIMD')

# Labels and title
plt.xlabel('Number of Threads')
plt.ylabel('Speedup')
plt.title('Scalability between OpenMP and Pthread without SIMD')
plt.xticks(threads)
plt.legend()

plt.grid(True)
plt.tight_layout()
plt.show()
