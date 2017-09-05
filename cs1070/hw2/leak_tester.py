import os
import subprocess
import multiprocessing

tester_path = 'testdata/'
report_path = '../report.txt'
command = ['valgrind', '--leak-check=full', '--show-leak-kinds=all', '../tester']


def debug(file):
   print('Debugging', file + '...', end='') 
   proc = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE)

   out, err = proc.communicate(file.encode())
   with open(report_path, 'a') as o:
      o.write(err.decode())
   print('Done.')


def main():
   os.chdir(tester_path)
   pool = multiprocessing.Pool(os.cpu_count())
   pool.map(debug, os.listdir()) 
   print()  
   print('The repot is saved at', os.path.abspath(report_path))

if __name__ == '__main__':
   main() 
