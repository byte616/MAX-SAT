import matplotlib.pyplot as plt

# Data for speedup comparison
threads = [1, 2, 3, 4, 5, 6]
openmp_speedup = [1, 1.86, 2.32, 2.63, 3.012, 3.38]
pthread_speedup = [1, 1.85, 2.35, 2.75, 3.07, 3.42]

# Create line plot for speedup comparison
plt.figure(figsize=(10, 6))

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

