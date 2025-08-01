from body import Body
import matplotlib.pyplot as plt

body = Body(1)

simulation_rate = 10000
dt = 1/simulation_rate


for i in range(1000):
    body.update(100,10,20,dt)


plt.plot(body.previous_position)
plt.show()

print(body.previous_position)