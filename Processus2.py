import os
pid_fils1 = os.fork()
if pid_fils1 == 0:
    print("Je suis le fils1")
else:
    print("Je suis le père")
    pid_fils2 = os.fork()
    if pid_fils2 == 0:
        print("Je suis le fils2")
