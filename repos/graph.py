# -*- coding: utf-8 -*-
"""
Created on Sun Dec  1 13:09:31 2019

@author: Nguyen Cong Thanh
"""

def f(x):
    return x**2 + 5

from matplotlib import pyplot as plt

# Create an array of x values from 0 to 10 to plot
x = list(range(0, 11))

# Use the function to get the y values
y = [f(i) for i in x]

# Set up the graph
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid()

# Plot the function
plt.plot(x,y, color='green')

plt.show()
