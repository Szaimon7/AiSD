import matplotlib
import numpy as np

matplotlib.use('Agg')
import matplotlib.pyplot as plt

n = np.array([100, 500, 2000, 4000, 10000, 15000])
operacje_IS = np.array([12562, 325000, 4915401, 20145904, 126652394, 290871903])
operacje_IS2 = np.array([8612, 214073, 3322841, 13388674, 84362784, 186754302])
operacje_MS = np.array([5473, 36061, 175096, 384483, 1075786, 1676090])
operacje_MS2 = np.array([5127, 35127, 171061, 366495, 1000876, 1557649])
operacje_HP = np.array([3035, 20890, 102945, 225330, 631610, 988820])
operacje_HP2 = np.array([2655, 17454, 85308, 184419, 511287, 802962])

n_log2_n = n * np.log2(n)
n_log3_n = n * np.log(n) / np.log(3)

plt.figure(figsize=(10, 6))

plt.plot(n, operacje_IS, marker='o', label='Insertion Sort')
plt.plot(n, operacje_IS2, marker='o', label='Insertion Sort zmodyfikowany')
plt.plot(n, operacje_MS, marker='o', label='Merge Sort')
plt.plot(n, operacje_MS2, marker='o', label='Merge Sort zmodyfikowany')
plt.plot(n, operacje_HP, marker='o', label='Heap Sort')
plt.plot(n, operacje_HP2, marker='o', label='Heap Sort zmodyfikowany')

plt.plot(n, n_log2_n, '--', color='grey', label='n * log2(n)')
plt.plot(n, n_log3_n, '--', color='black', label='n * log3(n)')

plt.xlabel("Liczba elementów n")
plt.ylabel("Liczba operacji (log)")
plt.yscale('log')
plt.title("Porównanie liczby operacji od liczby elementów")
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.savefig("Wykres operacji od czasu")
plt.close()
