import matplotlib.pyplot as plt

# Data for run time comparison
methods = ['serial', 'openMP', 'pthread', 'openMP+SIMD', 'pthread+SIMD']
run_times = [3.8504, 0.9882, 0.9151,  0.4894, 0.4838]
speedups = [1, 3.98, 4.2, 7.86, 7.95]

# Update global font size
plt.rcParams.update({'font.size': 20})

# Create combined plot for run time and speedup with adjusted annotation
fig, ax1 = plt.subplots(figsize=(10, 6))

# Bar plot for run time
bars = ax1.bar(methods, run_times, color='skyblue', alpha=0.7)
ax1.set_xlabel('Methods', fontsize=14)
ax1.set_ylabel('Run Time (seconds)', color='blue')
ax1.tick_params(axis='y', labelcolor='blue')
ax1.set_title('Run Time and Speedup Comparison')

# Annotate run time values on top of each bar
for bar in bars:
    yval = bar.get_height()
    ax1.text(bar.get_x() + bar.get_width() / 2, yval + 0.1, f'{yval:.4f} s', 
             ha='center', va='bottom', fontsize=12, color='blue')

# Line plot for speedup
ax2 = ax1.twinx()
ax2.plot(methods, speedups, marker='o', linestyle='-', color='orange')
ax2.set_ylabel('Speedup', color='orange')
ax2.tick_params(axis='y', labelcolor='orange')

# Annotate speedup values on the line plot
for i, speedup in enumerate(speedups):
    y_offset = -0.5 if speedup == 4.2 else 0.2
    ax2.text(i, speedup + y_offset, f'{speedup:.2f}x', 
             ha='center', va='bottom', color='orange')

plt.xticks(rotation=45, ha='right')
plt.tight_layout()
plt.show()

