# -*- coding: utf-8 -*-
"""
Created on Sat Aug 19 15:20:55 2023

@author: Luisa Bohórquez
"""

letras= 'ABCDEFG'
contadordeletras=1
espacios= ' '
contadordeespacios=11
controladorMostrarLetra=1
nletrasdisminuyendo=1

for i in range(13):
    if contadordeletras<=7:
        letrasmostradas= letras[0:contadordeletras]
        if contadordeletras<=6:
            resultado= letrasmostradas + espacios*contadordeespacios + letrasmostradas[::-1]
            contadordeespacios-=2
        else:
            resultado= letrasmostradas + espacios*contadordeespacios + letrasmostradas[::-1][1:]
            contadordeespacios+=2
        print(resultado)
        
    else:
        resultado= letras[:len(letras)-nletrasdisminuyendo] + espacios*contadordeespacios + letras[:len(letras)-nletrasdisminuyendo][::-1]
        print(resultado)
        nletrasdisminuyendo+=1
        contadordeespacios+=2
    
    contadordeletras+=1