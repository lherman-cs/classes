from random import randint
import os
from multiprocessing import Pool

FILENAME = 'input.txt'

# Default number of inputs
n = 1000000

# Default limit
limit = 1000000

# Delete if the output file exists
if os.path.exists(FILENAME):
   os.remove(FILENAME)

file = open(FILENAME, 'w+')


def write(i):
   file.write(str(randint(-limit, limit)) + '\n')

pool = Pool(os.cpu_count())


print('Generating random numbers')
pool.map(write, range(n))

file.close()
print('Generated!')




