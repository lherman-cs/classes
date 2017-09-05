#!/usr/bin/python3

from random import randint

n_cases = 5
lim = 400

print('Generating your test cases...')
with open('test.dat', 'w') as o:
   for _ in range(n_cases):
      n = randint(0, lim)
      o.write('{}\n'.format(n))

print('Generated!')
