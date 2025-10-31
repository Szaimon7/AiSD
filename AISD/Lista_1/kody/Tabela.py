import pandas as pd

n = [100, 500, 2000, 4000, 10000, 15000]
sortowania = ['Insertion Sort', 'Insertion Sort zmodyfikowany', 'Merge Sort', 'Merge Sort zmodyfikowany', 'Heap Sort', 'Heap Sort zmodyfikowany']

czas = {
    'Insertion Sort': [15, 362, 4224, 21648, 105795, 286321],
    'Insertion Sort zmodyfikowany': [11, 264, 2815, 13271, 78901, 196872],
    'Merge Sort': [39, 270, 856, 2644, 4755, 6504],
    'Merge Sort zmodyfikowany': [67, 265, 1031, 2629, 5121, 7372],
    'Heap Sort':[26, 180, 749, 1853, 5825, 9582],
    'Heap Sort zmodyfikowany':[26, 166, 671, 1754, 4015, 6488]
}


operacje = {
    'Insertion Sort': [12562, 325000, 4915401, 20145904, 126652394, 290871903],
    'Insertion Sort zmodyfikowany': [8612, 214073, 3322841, 13388674, 84362784, 186754302],
    'Merge Sort': [5473, 36061, 175096, 384483, 1075786, 1676090],
    'Merge Sort zmodyfikowany': [5127, 35127, 171061, 366495, 1000876, 1557649],
    'Heap Sort':[3035, 20890, 102945, 225330, 631610, 988820],
    'Heap Sort zmodyfikowany':[2655, 17454, 85308, 184419, 511287, 802962]
}


rows = []
for i, size in enumerate(n):
    for s in sortowania:
        rows.append({
            'n': size,
            'Sortowanie': s,
            'Czas [µs]': czas[s][i],
            'Operacje': operacje[s][i]
        })


df = pd.DataFrame(rows)


print(df)

df.to_csv("tabela_AiSD.csv", index=False)


