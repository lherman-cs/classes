#!/usr/bin/python3

from multiprocessing import Pool

def is_perfect(n):
   n = int(n)
   i = 2
   sum = 1
   
   if n == 1:
      sum = -1
    
   while i * i <= n:
      if n % i == 0:
         sum += i + n // i
      i += 1

   return '{} {}'.format(n, 1 if sum == n else 0)


MAX=10000
with Pool() as p:
   results = p.map(is_perfect, range(MAX))

with open('data.txt', 'w') as o:
   o.write('\n'.join(results))
