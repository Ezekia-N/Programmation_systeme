import os
pid_fils = os.fork()
print("Je suis le fils" if pid_fils == 0 else "Je suis le père")
