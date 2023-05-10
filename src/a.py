import numpy as np

ascii_dicionario = dict()
ascii_in_number = range(0,256)
for i in ascii_in_number:
    ascii_dicionario[str(i)] = chr(i)

ascii_dicionario = {v: k for k, v in ascii_dicionario.items()}

def codificar(mensagem, dic,chave):
    while len(mensagem)%3 != 0:
        mensagem += " "

    linha1 = []
    linha2 = []
    linha3 = []
    for i in mensagem:
        if len(linha1) < len(mensagem)/3:
            linha1.append(dic[str(i)])
        elif len(linha1) == len(mensagem)/3 and len(linha2) < len(mensagem)/3:
            linha2.append(dic[str(i)])
        else:
            linha3.append(dic[str(i)])
    codigo = np.array([list(map(int,linha1)),list(map(int,linha2)),list(map(int,linha3))])
    chave = np.array(chave)
    codigo = np.matmul(chave,codigo)
    print(codigo)
def decodificar(matriz, chave, dic):
    matriz = np.matmul(chave,matriz)
    mensagem = ""
    dic = {v: k for k, v in dic.items()}
    for i in matriz:
        for j in i:
            mensagem += dic[str(int(j))]
    print(mensagem.strip())
perg1 = input("Digite 'c' para codificar e 'd' para decodificar.")
if perg1.lower().strip() == 'c':
    mensagem = input("Digite a mensagem a ser codificada: ")
    print("Deseja informar a matriz inversível que será usada para criptografar?")
    deschave = input("Digite 's' para sim ou 'n' para não: ")
    if deschave.lower().strip() == 's':
        primeira_chave = input("Digite os valores da primeira linha da matriz (separadando por um espaço): ").split(" ")
        segunda_chave = input("Digite os valores da segunda linha da matriz (separadando por um espaço): ").split(" ")
        terceira_chave = input("Digite os valores da terceira linha da matriz (separadando por um espaço): ").split(" ")
        chave = np.array([list(map(int,primeira_chave)), list(map(int,segunda_chave)), list(map(int,terceira_chave))])
    elif deschave.lower().strip() == 'n':
        print("A matriz utilizada será:")
        print("1 2 3")
        print("0 1 4")
        print("0 0 1")
        chave = np.array([[1,2,3],[0,1,4],[0,0,1]])
    try:
        np.linalg.inv(chave)
        codificar(mensagem,ascii_dicionario,chave)
    except:
        print("Matriz não é invertível.")
elif perg1.lower().strip() == 'd':
    primeira_matriz = input("Digite os valores da primeira linha da matriz (separadando por um espaço): ").split(" ")
    segunda_matriz = input("Digite os valores da segunda linha da matriz (separadando por um espaço): ").split(" ")
    terceira_matriz = input("Digite os valores da terceira linha da matriz (separadando por um espaço): ").split(" ")
    matriz = np.array([list(map(int,primeira_matriz)), list(map(int,segunda_matriz)), list(map(int,terceira_matriz))])
    primeira_chave = input("Digite os valores da primeira linha da matriz inversível (separadando por um espaço): ").split(" ")
    segunda_chave = input("Digite os valores da segunda linha da matriz inversível (separadando por um espaço): ").split(" ")
    terceira_chave = input("Digite os valores da terceira linha da matriz inversível (separadando por um espaço): ").split(" ")
    chave = np.array([list(map(int,primeira_chave)), list(map(int,segunda_chave)), list(map(int,terceira_chave))])
    try:
        chave = np.linalg.inv(chave)
        decodificar(matriz,chave,ascii_dicionario)
    except:
        print("Matriz não é invertível.")