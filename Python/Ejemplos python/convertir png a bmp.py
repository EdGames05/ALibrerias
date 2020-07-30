from PIL import Image
from os import scandir, getcwd
from os.path import abspath
import os

def ls(ruta = input("Escriba una ruta: ")):
    try:
        os.stat(ruta + "/bitmaps")
    except IOError:
        os.mkdir(ruta + "/bitmaps")
    
    return [abspath(arch.path) for arch in scandir(ruta) if arch.is_file()], ruta

def main():
    archivos, ruta = ls()
    if archivos == "":
        print("Ocurrio un error")
        return
    
    for archivo in archivos:
        try:
            img = Image.open(archivo)
            img.save(ruta + "/bitmaps/" + os.path.basename(archivo.replace(".png","")) + ".bmp")
        except IOError:
            print(archivo + " no es una imagen\n")


if __name__ == "__main__":
    main()
