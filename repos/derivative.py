def f(x):
    return 1/x

def derivative(x):
    h= 1./1000000.
    rise = f(x+h) - f(x)

    run = h
    slope = rise / run
    return slope

from matplotlib import pyplot as plt

# Create an array of x values from 0 to 10 to plot
x = list(range(1, 11))

# Use the function to get the y values
y = [f(i) for i in x]

# Set up the graph
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid()

# Plot the function
plt.plot(x,y, color='green')

plt.show()
