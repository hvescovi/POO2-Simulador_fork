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
            raio = randint(10,15)
            velMax = randint(30, 45)
            # 800x600 tela
            x = randint(30+raio, 1250-raio)
            y = randint(30+raio, 690-raio)

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

def main2():
    numSims = int(input("Numero de simulações: "))
    numCirc = 300
    listaCirc = []
    round = 0
    b = 0
    for vez in range(0, numSims):
        listaCirc = []
        round = 0
        while round != numCirc:
            raio = randint(10,15)
            velMax = randint(30, 45)
            # 1280x720 tela
            x = randint(30+raio, 1250-raio)
            y = randint(30+raio, 690-raio)

            if (verColisao(x, y, raio, listaCirc)):
                listaCirc.append([x,y,raio,velMax])
                round += 1

        for v in range(0,5):
            with open(f"simu_{b}.txt", "w") as a:
                num = v+1
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
            b+=1

        

if __name__ == "__main__":
    if int(input("Digite a alternativa: ")) == 1:
        main()
    else:
        main2()