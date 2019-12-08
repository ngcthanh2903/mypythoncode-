
def f(x):
    return x**2


from matplotlib import pyplot as plt

# Create an array of x values from 0 to 10 to plot
x = list(range(1, 11))

# Use the function to get the y values
y = [f(i) for i in x]

# Set the x point
x1 = 3
y1 = f(x1)

# set the increment
h = 3

# set the x+h point
x2 = x1+h
y2 = f(x2)

# Set up the graph
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid()

# Plot the function
plt.plot(x,y, color='blue')

# Plot the x point
plt.scatter(x1,y1, c='red')
plt.annotate('(x,f(x))',(x1,y1), xytext=(x1-0.01, y1+0.01))

# Plot the x+h point
plt.scatter(x2,y2, c='gold')
plt.annotate('(x+h, f(x+h))',(x2,y2), xytext=(x2+0.01, y2-0.01))


  
plt.show()


