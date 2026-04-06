import sys

def add(a, b):
    return a + b

if len(sys.argv) < 3:
    print(f"Usage : {sys.argv[0]} nombre1 nombre2")
    exit(1)

print(f"Somme : {int(sys.argv[1]) + int(sys.argv[2])}")
