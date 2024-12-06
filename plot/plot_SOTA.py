import matplotlib.pyplot as plt

methods = ['openmp + SIMD', 'serial', 'simulated annealing', 'stochastic hill climbing search', 'tabu search']
run_times = [0.007, 0.035, 2.315, 8.3452, 272.957]

plt.figure(figsize=(10, 6))
bars = plt.bar(methods, run_times, color='skyblue')

# Add value labels on top of each bar, reducing the offset
for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width() / 2, yval + 0.5 if yval > 1 else yval + 0.01, f'{yval:.3f} s', ha='center', va='bottom', fontsize=10)

# Adjust y-axis limit to ensure all labels fit
plt.ylim(0, max(run_times) * 1.1)

plt.ylabel('Run Time (seconds)')
plt.title('Comparison of Different Solver')
plt.xticks(rotation=45, ha='right')
plt.tight_layout()

plt.show()

