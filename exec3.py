import os
fichier = input("Entrez ici le nom du fichier : ")
os.execv("/usr/bin/emacs", ["emacs", fichier])
