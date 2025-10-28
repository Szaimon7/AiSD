import pandas as pd

n = [100, 500, 2000, 15000]
sortowania = ['Insertion Sort', 'Insertion Sort zmodyfikowany', 'Merge Sort', 'Merge Sort zmodyfikowany']

czas = {
    'Insertion Sort': [15, 362, 4224, 286321],
    'Insertion Sort zmodyfikowany': [11, 264, 2815, 196872],
    'Merge Sort': [39, 270, 856, 6504],
    'Merge Sort zmodyfikowany': [67, 265, 1031, 7372]
}


operacje = {
    'Insertion Sort': [12562, 325000, 4915401, 290871903],
    'Insertion Sort zmodyfikowany': [8612, 214073, 3322841, 186754302],
    'Merge Sort': [5473, 36061, 175096, 1676090],
    'Merge Sort zmodyfikowany': [5127, 35127, 171061, 1557649]
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

