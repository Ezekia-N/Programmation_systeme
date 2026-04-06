import os

pwd = os.getenv("PWD")

while(True):
    repertoire = input("Entrez ici le chemin de destination ou entrez q pour quitter : ")
    if repertoire == "q":
        break
    fils = os.fork()
    if fils == 0:
        os.execl("/usr/bin/cp", "cp", "-rf", pwd, repertoire)