import matplotlib.pyplot as plt

def criarLista(resultados):
    eixoX = []
    contagemTemplates = []
    for i in resultados:
        eixoX.append(i[0])
    eixoX = set(eixoX)
        
    for i in range(0, len(eixoX)):
        contagemTemplates.append(0)

    for i in resultados:
        contagemTemplates[i[0] -1] += 1
    
    return contagemTemplates, eixoX

def main():

    '''
    variavel linha:
    0 -> template
    1 -> circulos iniciados
    2 -> circulos mortos
    3 -> tempo da simulacao (segundos)
    
    grafico:
    x -> template
    y -> media circulos que fugiram

    terminal:
    tempo medio e qtde circulos
    '''

    # Todos os resultados com numeros inteiros
    resultados = []
    circFuga = []
    qtdSim = 0
    tempoTotal = 0

    with open("res_sim.txt", "r") as res:
        for i in res.readlines():
            qtdSim += 1
            linha = i.split(";")
            # Transforma os itens em inteiros
            for j in linha:
                if j.endswith("\n"):
                    linha[linha.index(j)] = int(j[:-1])
                else:
                    linha[linha.index(j)] = int(j)
            resultados.append(linha)

        TemplateseixoX = criarLista(resultados)
        contagemTemplates = TemplateseixoX[0]
        eixoX = TemplateseixoX[1]
        eixoX = list(eixoX)

        for i in eixoX:
            circFuga.append(0)

        for i in resultados:
            circFuga[i[0] - 1] += i[2]
            tempoTotal += i[3]

        for i in range(len(eixoX)):
            circFuga[i] /= contagemTemplates[i]
    
    tempoMedio = tempoTotal/qtdSim
    print("----------------")
    print("Templates:")
    cont = 0
    for i in eixoX:
        print(f"Template {i}: {circFuga[cont]} circulos que fugiram.")
        cont += 1
    print("----------------")
    print(f"As simulacoes tinham {resultados[0][1]} circulos.")
    print("----------------")
    print(f"Tempo medio de {tempoMedio} segundos")


    plt.plot(eixoX, circFuga, 'ro')
    plt.xticks(eixoX)
    plt.yticks(circFuga)
    plt.xlabel("Template")
    plt.ylabel("Circulos Mortos")
    plt.grid(axis='y')
    plt.show()
    
if __name__ == "__main__":
    main()