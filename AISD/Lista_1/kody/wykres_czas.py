import matplotlib
import numpy as np
matplotlib.use('Agg')
import matplotlib.pyplot as plt

n = np.array([100, 500, 2000, 4000, 10000, 15000])
czas_IS = np.array([15, 362, 4224, 21648, 105795, 286321])
czas_IS2 = np.array([11, 264, 2815, 13271, 78901, 196872])
czas_MS = np.array([39, 270, 856, 2644, 4755, 6504])
czas_MS2 = np.array([67, 265, 1031, 2629, 5121, 7372])
czas_HP = np.array([26, 180, 749, 1853, 5825, 9582])
czas_HP2 = np.array([26, 166, 671, 1754, 4015, 6488])


n_log2_n = n * np.log2(n)
n_log3_n = n * (np.log(n) / np.log(3))


plt.figure(figsize=(10,6))


plt.plot(n, czas_IS, marker='o', label='Insertion Sort')
plt.plot(n, czas_IS2, marker='o', label='Insertion Sort zmodyfikowany')
plt.plot(n, czas_MS, marker='o', label='Merge Sort')
plt.plot(n, czas_MS2, marker='o', label='Merge Sort zmodyfikowany')
plt.plot(n, czas_HP, marker = 'o', label = 'Heap Sort')
plt. plot(n, czas_HP2, marker = 'o', label = 'Heap sort zmodyfikowany')


plt.plot(n, n_log2_n, '--', color='grey', label='n * log2(n)')
plt.plot(n, n_log3_n, '--', color='black', label='n * log3(n)')

plt.xlabel("Liczba elementów n")
plt.ylabel("Czas [µs] / n*log(n) (log)")
plt.yscale('log')
plt.title("Porównanie czasu od ilości elementów")
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.savefig("Wykres czasu od ilości posortowanych elementów")
plt.close()
