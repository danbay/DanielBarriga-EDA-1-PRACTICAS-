def decimal_a_binario(n):
    if n == 0:
        return '0'  # Caso especial para el número 0
    elif n < 0:
        return '-' + decimal_a_binario(-n)  # Manejo de números negativos
    elif n <= 1:
        return str(n)
    else:
        return decimal_a_binario(n // 2) + str(n % 2)


def fibonacci_inverso(n):
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        return [1, 0]
    else:
        fibo = fibonacci_inverso(n - 1)
        fibo.insert(0, fibo[0] + fibo[1])
        return fibo


while True:
    print("Menu de opciones:")
    print("1 - Conversión de bases")
    print("2 - Serie de Fibonacci")
    print("3 - Salir")

    opcion = int(input("Ingrese el número de opción: "))

    if opcion == 1:
        n = int(input("Ingrese un número entero: "))
        binario = decimal_a_binario(n)
        print("El número decimal", n, "equivale a", binario, "en binario.")
    elif opcion == 2:
        n = int(input("Ingrese un número entero: "))
        serie = fibonacci_inverso(n)
        print("Los primeros", n, "términos de la serie de Fibonacci en orden inverso son:", serie)
    elif opcion == 3:
        print("¡Hasta luego!")
        break
    else:
        print("Opción inválida. Por favor, ingrese una opción válida.")