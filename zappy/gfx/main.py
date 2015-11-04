from connexions import Sock
from game import Game
from tile import GameWindow
import sys
import pyglet

window_width = 1600
window_height = 900

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print "usage: python main.py host port"
        exit()
    s = Sock(sys.argv[1], sys.argv[2])
    g = Game(s)
    g.loop_until_msz()
    game = GameWindow(g.x, g.y, g, width=window_width, height=window_height)
    pyglet.app.run()
