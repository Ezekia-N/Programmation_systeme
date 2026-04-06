import os
import sys

if len(sys.argv) != 2:
    print(f"Usage : {sys.argv[0]} chemin_de_destination")
    exit(1)

pwd = os.getenv("PWD")

os.execl("/usr/bin/cp", "cp", "-rf", pwd, sys.argv[1])