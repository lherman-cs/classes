from random import randint, randrange
from multiprocessing import Pool
from os.path import abspath
from os import listdir
from sys import stderr
from subprocess import Popen, PIPE

class Tester:
    commands = ["insert", "remove", "find"]
    max_steps = 10
    min = -10
    max = 10
    filename = "input.txt"

    def __init__(self):
        self.commands = self.generate_test()
        self.results = []

    def generate_command(self, _):
        command = self.commands[randrange(len(self.commands))]
        number = randint(self.min, self.max)
        return "{} {}".format(command, number)

    def generate_test(self):
        print("Generating test...", file=stderr)
        steps = randint(1, self.max_steps)
        with Pool() as p:
            commands = p.map(self.generate_command, range(steps))
        commands.append("print")
        commands.append("quit")

        with open(self.filename, "w") as o:
            o.write("\n".join(commands))
        print("Test input is stored at {}".format(abspath(self.filename)), file=stderr)
        return commands

    def run_all(self):
        self.run()
        self.run_c()

    def run(self):
        print("Answer".center(80, "="))
        for command in self.commands:
            command = command.split()

            if command[0] == "insert":
                self.insert(int(command[1]))
            elif command[0] == "remove":
                self.remove(int(command[1]))
            elif command[0] == "find":
                self.find(int(command[1]))
            else:
                pass

        print("Contents of structure in sorted order:")
        for result in self.results:
            print(result)

    def insert(self, value):
        if value in self.results:
            print("Error!  Key {} already in structure!".format(value))
        else:
            self.results.append(value)
            self.results.sort()

    def remove(self, value):
        try:
            self.results.remove(value)
        except:
            print("Error!  Key {} not in structure!".format(value))

    def find(self, value):
        if value in self.results:
            print("Key {} present.".format(value))
        else:
            print("Key {} absent.".format(value))

    def compile_c(self):
        files = listdir()
        files = [file for file in files if file.endswith('.cpp')]
        p = Popen(["g++", "-o", "main"] + files, stdout=PIPE, stderr=PIPE)
        out, err = p.communicate()
        if err:
            print(err.decode())

    def run_c(self):
        self.compile_c()
        p = Popen(["./main"], stdout=PIPE, stderr=PIPE, stdin=PIPE)
        out, err = p.communicate("\n".join(self.commands).encode())
        print("Output".center(80, "="))
        print(out.decode())

tester = Tester()
tester.run_all()
