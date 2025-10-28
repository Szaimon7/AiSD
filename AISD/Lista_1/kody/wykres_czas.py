import matplotlib
import numpy as np
matplotlib.use('Agg')
import matplotlib.pyplot as plt

n = np.array([100, 500, 2000, 15000])
czas_IS = np.array([15, 362, 4224, 286321])
czas_IS2 = np.array([11, 264, 2815, 196872])
czas_MS = np.array([39, 270, 856, 6504])
czas_MS2 = np.array([67, 265, 1031, 7372])


n_log2_n = n * np.log2(n)
n_log3_n = n * np.log(n) / np.log(3)


plt.figure(figsize=(10,6))


plt.plot(n, czas_IS, marker='o', label='Insertion Sort')
plt.plot(n, czas_IS2, marker='o', label='Insertion Sort zmodyfikowany')
plt.plot(n, czas_MS, marker='o', label='Merge Sort')
plt.plot(n, czas_MS2, marker='o', label='Merge Sort zmodyfikowany')


plt.plot(n, n_log2_n, '--', color='grey', label='n * log2(n)')
plt.plot(n, n_log3_n, '--', color='black', label='n * log3(n)')

plt.xlabel("Liczba elementów n")
plt.ylabel("Czas [µs] / n*log(n) (log)")
plt.yscale('log')
plt.title("Porównanie czasu sortowań z n*log(n)")
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.savefig("Wykres czasu od ilości posortowanych elementów")
plt.close()
