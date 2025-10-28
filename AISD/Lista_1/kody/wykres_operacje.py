import matplotlib
import numpy as np
matplotlib.use('Agg')  # backend bez GUI
import matplotlib.pyplot as plt


n = np.array([100, 500, 2000, 15000])
operacje_IS = np.array([12562, 325000, 4915401, 290871903])
operacje_IS2 = np.array([8612, 214073, 3322841, 186754302])
operacje_MS = np.array([5473, 36061, 175096, 1676090])
operacje_MS2 = np.array([5127, 35127, 171061, 1557649])

n_log2_n = n * np.log2(n)
n_log3_n = n * np.log(n) / np.log(3)


plt.figure(figsize=(10,6))


plt.plot(n, operacje_IS, marker='o', label='Insertion Sort')
plt.plot(n, operacje_IS2, marker='o', label='Insertion Sort zmodyfikowany')
plt.plot(n, operacje_MS, marker='o', label='Merge Sort')
plt.plot(n, operacje_MS2, marker='o', label='Merge Sort zmodyfikowany')


plt.plot(n, n_log2_n, '--', color='grey', label='n * log2(n)')
plt.plot(n, n_log3_n, '--', color='black', label='n * log3(n)')

plt.xlabel("Liczba elementów n")
plt.ylabel("Liczba operacji (log)")
plt.yscale('log')
plt.title("Porównanie liczby operacji sortowań z n*log(n)")
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.savefig("wykres_operacje_n_log_n.png")
plt.close()