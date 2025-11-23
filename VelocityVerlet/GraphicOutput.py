import pandas as pd
import matplotlib.pyplot as plt
import os
print(os.getcwd())

# absolutní cesta k CSV
df = pd.read_csv(r"C:\Users\mafia\Documents\Projects\vystup.csv")

# vykreslení
plt.plot(df['x_zeme'], df['y_zeme'], label='Země', color='blue')
plt.xlabel('x [jednotky simulace]')
plt.ylabel('y [jednotky simulace]')
plt.title('Trajektorie Země')
plt.grid(True)
plt.axis('equal')
plt.legend()
plt.show()
