# -*- coding: utf-8 -*-
"""
Created on Mon Aug 14 15:58:16 2023

@author: Luisa Bohórquez
"""

Letra='ABCDEFG'
e=' '
j=13
l=1

for i in range(0,7):
    m= Letra[0:l]
    if i!=6:
        p=m+e*(j-2)+m[::-1]
        z=m[::-1]
    else:
        p=m+e*(j-2)+z    
    l=l+1
    j=j-2
    print(p)