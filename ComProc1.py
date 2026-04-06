import os
import struct 

r1, w1 = os.pipe()
r2, w2 = os.pipe()

fils = os.fork()
if fils == 0:
    os.close(w2)
    os.close(r1)

    bufferw = input("Entrez le mot à rechercher : ")
    os.write(w1, bufferw.encode())
    resultatR = os.read(r2, 4)
    resultatR = struct.unpack('i', resultatR)[0]
    print(f"Resultat de recherche : {resultatR}")

    os.close(w1)
    os.close(r2)
else:
    os.close(w1)
    os.close(r2)

    resultatW = 0
    bufferR = os.read(r1, 100).decode()
    with open("fichier.txt", "r", encoding="utf-8") as fp:
        line = fp.readline()
    for word in line.split(" "):
        if word == bufferR:
            resultatW = 1
            break
    resultatW = struct.pack('i', resultatW)
    os.write(w2, resultatW)

    os.close(w2)
    os.close(r1)
