import os
import time
from random import randint

pid_fils1 = os.fork()
nbre_seconde = randint(1, 10)
t1 = time.perf_counter()

if pid_fils1 == 0:
    time.sleep(nbre_seconde)
else:
    pid_fils2 = os.fork()
    if pid_fils2 == 0:
        time.sleep(nbre_seconde)
    else:
        os.waitpid(pid_fils1, 0)
        os.waitpid(pid_fils2, 0)
        print(f"La durée totale : {round(time.perf_counter()-t1)}")