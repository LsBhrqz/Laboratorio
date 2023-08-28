# -*- coding: utf-8 -*-
"""
Created on Sat Aug 19 16:39:32 2023

@author: Luisa Bohórquez
"""
numero= input('Ingrese un número: ')
ban=True
suma=0
while ban:
    try:
        numero= int(numero)
        ban=False
    except:
        numero= input('La entrada es inválida, ingresa sólo números:')

division=str(numero)

for cifra in division:
    partes= int(cifra)**2
    suma+= partes
    
print(suma)