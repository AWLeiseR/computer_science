def DDA(x1, y1, x2, y2):
    step = abs(x2 - x1)
    if abs(y2 - y1) > step:
        step = abs(y2 - y1)
    xinc = (x2 - x1) / step
    yinc = (y2 - y1) / step
    x = x1
    y = y1
    print("Pontos que seram pintados")
    while x <= x2:
        print("(", round(x), ",", round(y), ")")
        x = x + xinc
        y = y + yinc


def main():
    print("insira dois pontos de uma reta:")
    x1 = input("insira o primeiro ponto x: ")
    y1 = input("insira o primeiro ponto y: ")
    x2 = input("insira o segundo ponto x: ")
    y2 = input("insira o segundo ponto y: ")
    DDA(int(x1), int(y1), int(x2), int(y2))


main()
