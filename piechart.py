import numpy as np
from matplotlib import pyplot as plt
languages=['python','java','PHP','javascript','C#','C++']
popularity=[22.2,17.6,8.8,8,7.7,6.7]
colors=['red','blue','yellow','pink','purple','orange']
explode=(0.1,0,0,0,0,0)
plt.pie(popularity,explode=explode,labels=languages,colors=colors,autopct='%1.1f%%',shadow=True,startangle=140)
