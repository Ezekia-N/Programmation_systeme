import os

pwd = os.getenv("PWD")

while(True):
    fichier = input("Entrez ici le nom de fichier ou entrez q pour quitter : ")
    if fichier == "q":
        break
    fils = os.fork()
    if fils == 0:
        os.execl("/usr/bin/emacs", "emacs", fichier)