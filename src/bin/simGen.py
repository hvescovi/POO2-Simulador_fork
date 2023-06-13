'''
//primeira linha: template
//segunda linha: circulos
#Circulos
pos.x pos.y raio vel_maxima
'''

from random import randint
from math import sqrt

def calcDist(x1, y1, x2, y2):
    x = x2 - x1
    y = y2 - y1
    return abs(sqrt(x**2 + y**2))


def verColisao(x,y, raio, listCirc):
    for i in listCirc:
        dist = calcDist(x,y, i[0], i[1])
        if (dist < raio + i[2]):
            return False
    return True

def main():
    numCirc = int(input("Numero de circunferencia: "))
    numSims = int(input("Numero de simulações: "))
    
    for b in range(0, numSims):
        listaCirc = []
        round = 0
        while round != numCirc:
            raio = randint(5,10)
            velMax = randint(20, 30)
            # 800x600 tela
            x = randint(10+raio, 790-raio)
            y = randint(10+raio, 590-raio)

            if (verColisao(x, y, raio, listaCirc)):
                listaCirc.append([x,y,raio,velMax])
                round += 1
        
        with open(f"simu_{b}.txt", "w") as a:
            num = randint(1,5)
            a.writelines(str(num) + "\n")
            
            for i in listaCirc:
                item = ''
                for j in i:
                    item += str(j) + " "
                if (len(listaCirc) - listaCirc.index(i) > 1):
                    item = item[:-1] + "\n"
                else:
                    item = item[:-1]
                a.writelines(item)        

if __name__ == "__main__":
    main()