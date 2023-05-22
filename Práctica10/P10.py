class Libro:
    def __init__(self, id, titulo):
        self.id = id
        self.titulo = titulo

def agregar_libro(biblioteca):
    titulo = input("Ingrese el título del libro: ")
    id = len(biblioteca) + 1
    libro = Libro(id, titulo)
    biblioteca.append(libro)
    print("Libro agregado con éxito.")

def eliminar_libro(biblioteca):
    titulo = input("Ingrese el título del libro a eliminar: ")
    for libro in biblioteca:
        if libro.titulo == titulo:
            biblioteca.remove(libro)
            print("Libro eliminado con éxito.")
            return
    print("No se encontró el libro en la biblioteca.")

# Función para ordenar la biblioteca por título o por ID
def ordenar_biblioteca(biblioteca):
    opcion = input("Ingrese '1' para ordenar por título o '2' para ordenar por ID: ")
    if opcion == '1':
        biblioteca.sort(key=lambda libro: libro.titulo)
        print("Biblioteca ordenada por título.")
    elif opcion == '2':
        biblioteca.sort(key=lambda libro: libro.id)
        print("Biblioteca ordenada por ID.")
    else:
        print("Opción inválida.")

# Función para mostrar el estado actual de la biblioteca
def ver_biblioteca(biblioteca):
    if len(biblioteca) == 0:
        print("La biblioteca está vacía.")
    else:
        print("Biblioteca:")
        for libro in biblioteca:
            print(f"ID: {libro.id}, Título: {libro.titulo}")

# Función principal del programa
def main():
    biblioteca = []
    while True:
        print("\nBienvenido a la biblioteca, puede realizar las siguientes operaciones:")
        print("1 - Agregar libro")
        print("2 - Eliminar libro")
        print("3 - Ordenar biblioteca")
        print("4 - Ver biblioteca")
        print("5 - Salir")

        opcion = input("Ingrese una opción: ")
        
        if opcion == '1':
            agregar_libro(biblioteca)
        elif opcion == '2':
            eliminar_libro(biblioteca)
        elif opcion == '3':
            ordenar_biblioteca(biblioteca)
        elif opcion == '4':
            ver_biblioteca(biblioteca)
        elif opcion == '5':
            print("¡Hasta luego!")
            break
        else:
            print("Opción inválida. Por favor, ingrese una opción válida.")

# Llamar a la función principal para iniciar el programa
main()