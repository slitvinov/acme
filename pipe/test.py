import matplotlib.pyplot as plt
import numpy as np
from numpy.linalg import det

def norm_pdf(x, mu, sigma2): return 1 / np.sqrt(2 * np.pi * sigma2) * np.exp(-(x - mu)**2 / (2 * sigma2))
xrange = np.linspace(-4, 4, 100)
plt.plot(xrange, norm_pdf(xrange, 0, 1), label=r"$\mu=0; \ \sigma^2=1$")
plt.plot(xrange, norm_pdf(xrange, 1, 2), label=r"$\mu=1; \ \sigma^2=2$")
plt.plot(xrange, norm_pdf(xrange, -1, 3), label=r"$\mu=-1; \ \sigma^2=3$")
plt.legend(fontsize=15)

plt.show()
