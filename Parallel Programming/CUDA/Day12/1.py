import numpy as np

MAX_RECORDS = 100000

file_path = "movies.csv"

h_gross = []
h_votes = []

with open(file_path, "r") as fp:
    next(fp)
    
    for line in fp:
        columns = line.strip().split(",")
        if len(columns) > 7:
            try:
                votes = float(columns[5])
                gross = float(columns[6])
                if votes > 0 and gross > 0:
                    h_votes.append(votes)
                    h_gross.append(gross)
            except ValueError:
                continue 
                
        if len(h_votes) >= MAX_RECORDS:
            break

h_votes = np.array(h_votes, dtype=np.float32)
h_gross = np.array(h_gross, dtype=np.float32)
record_count = len(h_votes)

print("First 10 h_votes:", h_votes[:10])
print("First 10 h_gross:", h_gross[:10])

x_sum = np.sum(h_votes)
y_sum = np.sum(h_gross)
xy_sum = np.sum(h_votes * h_gross)
xx_sum = np.sum(h_votes * h_votes)

slope = (record_count * xy_sum - x_sum * y_sum) / (record_count * xx_sum - x_sum ** 2)
intercept = (y_sum - slope * x_sum) / record_count

print(f"Slope: {slope:.2f}")
print(f"Intercept: {intercept:.2f}")
