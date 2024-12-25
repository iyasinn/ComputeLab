# import matplotlib.pyplot as plt
# import pandas as pd

# # Load data from CSV
# data = pd.read_csv('output.csv')

# # Assuming the CSV has columns 'x' and 'y'
# plt.plot(data['x'], data['y'])
# plt.xlabel('X-axis')
# plt.ylabel('Y-axis')
# plt.title('Graph from CSV')
# # plt.show()
# plt.savefig("graph")

import plotly.express as px
import pandas as pd

# Load data
data = pd.read_csv('output.csv')

# Create an interactive plot
fig = px.line(data, x='batch', y='time', title='Graph from CSV')
fig.show()