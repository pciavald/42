# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gui.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/25 13:17:39 by pciavald          #+#    #+#              #
#    Updated: 2014/06/26 20:51:58 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time
import sys
sys.path.append("networkx")
import networkx as nx
import matplotlib.pyplot as plt
import subprocess as sp
from matplotlib.lines import Line2D
import matplotlib.animation as animation
import numpy as np

ft_map = sys.argv[1]
with open(ft_map) as f:
	content = f.readlines()

cmd = ['./script.sh', ft_map]
out = sp.Popen(cmd, stdout = sp.PIPE).communicate()[0]
out = out.strip().split("\n")

G = nx.Graph()

def init():
	for line in content:
		if len(line.split(" ")) == 3:
			split = line.split(" ")
			G.add_node(int(split[0]), 
					pos = (int(split[1]), int(split[2])), 
					color = 'w')
		elif (len(line.split("-")) == 2):
			split = line.split("-")
			G.add_edge(int(split[0]), int(split[1]))

def draw():
	plt.clf()
	plt.axis('off')
	plt.ion()
	pos = nx.get_node_attributes(G, 'pos')
	nx.draw(G, pos, node_color = 'grey')
	nx.draw_networkx_nodes(G, pos, nodelist=ants, node_color = 'b')
	nx.draw_networkx_nodes(G, pos, nodelist=[start], node_color = 'r')
	nx.draw_networkx_nodes(G, pos, nodelist=[end], node_color = 'g')
	plt.draw()
	plt.show()

def simData(a, b, name):
	t_max = 1.0
	dt = 0.1
	t = 0
	dx = b[0] - a[0]
	dy = b[1] - a[1]
	npos = [float(a[0]), float(a[1])]
	while (t < t_max):
		npos[0] = float(a[0]) + dx * t / t_max
		npos[1] = float(a[1]) + dy * t / t_max
		G.node[name]['pos'] = (npos[0], npos[1])
		t += dt
		init()
		draw()

init()
start = int(content[content.index("##start\n") + 1].split(" ")[0])
end = int(content[content.index("##end\n") + 1].split(" ")[0])
ants = []

for step in out:
	group = step.split(" ")
	for bloc in group:
		bloc = bloc[1:]
		split = bloc.split("-")
		if (len(split) == 2):
			if (nx.nodes(G).count(split[0]) == 0):
				G.add_node(
						split[0],
						pos = nx.get_node_attributes(G, 'pos')[start],
						color = 'b'
						)
				ants.append(split[0])
			currentPoint = nx.get_node_attributes(G, 'pos')[split[0]]
			nextPoint = nx.get_node_attributes(G, 'pos')[int(split[1])]
			simData(currentPoint, nextPoint, split[0])
