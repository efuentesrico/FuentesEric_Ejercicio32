import numpy as np
import matplotlib.pyplot as plt


wave = np.loadtxt("wave.dat")
x=np.linspace(0,1,wave.shape[1])


plt.figure()
plt.plot(x,wave[0],label="Tiempo inicial")
plt.plot(x,wave[-1],label="Tiempo final")
plt.legend()
plt.xlabel("Posicion [metros]")
plt.ylabel("Desplazamiento [metros]")

plt.savefig("wave.png")