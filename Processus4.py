import os
for i in range(1, 6):
    pid_fils = os.fork()
    if pid_fils == 0:
        print(f"Je suis le fils {i}")
        break

