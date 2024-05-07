#------------------------------------------------------------------------------
#  Imports
#------------------------------------------------------------------------------

import random
import numpy as np
from matplotlib import pyplot as plt

#------------------------------------------------------------------------------
#  Global variables
#------------------------------------------------------------------------------

n = 40  # number of random numbers to average

#------------------------------------------------------------------------------
#  Function definitions
#------------------------------------------------------------------------------


# average()
# returns average of 10 random numbers between 0 and 1
def average():
    # create list of random numbers
    randNums = []
    for i in range(n):
        randNums.append(random.random())
    # end for
    # average the numbers
    avg = sum(randNums) / len(randNums)

    return avg
# end average()

#------------------------------------------------------------------------------
# Main Program
#------------------------------------------------------------------------------


# make a list of averages
avgNums = []
for j in range(100):
    avgNums.append(average())
# end for

# average and standard deviation of the averages
avg = sum(avgNums) / len(avgNums)
dev = []
for k in range(len(avgNums)):
    dev.append((avgNums[k] - avg)**2)
# end for
SD = np.sqrt(sum(dev) / len(dev))

# expected SEM
flatSD = 1 / np.sqrt(12)  # expected SD for flat distribution
SEM = flatSD / np.sqrt(n)

print('Average:', avg)
print('Standard Deviation:', SD)
print('SEM:', SEM)

# create histogram of averages
averages = np.array(avgNums)
fig, ax = plt.subplots(figsize=(10, 7))
ax.hist(averages, bins=[0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5,
                 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0])
# create Gaussian distribution function
x = np.linspace(0, 1, 100)
y = (5 / (np.sqrt(2*np.pi)*SEM)) * np.exp(-((x-0.5)**2) / (2*(SEM**2)))
plt.plot(x, y)
plt.xlabel('Random length averages (m)')
plt.ylabel('Frequency')
plt.title('n = '+str(n))
plt.show()

