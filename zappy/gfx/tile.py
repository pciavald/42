import pyglet
from math import floor
import pyglet.window.key as key
import pyglet.window.mouse as mouse
from threading import Thread


egg = pyglet.image.load('egg.png')
food = pyglet.image.load('food.png')
linemate = pyglet.image.load('stone7.png')
deraumere = pyglet.image.load('stone3.png')
sibur = pyglet.image.load('stone6.png')
mendiane = pyglet.image.load('stone4.png')
phiras = pyglet.image.load('stone1.png')
thystame = pyglet.image.load('stone8.png')

objects = {
    0: food,
    1: linemate,
    2: deraumere,
    3: sibur,
    4: mendiane,
    5: phiras,
    6: thystame,
    }

coord = {
    0: [-20, 30],
    1: [8, 20],
    2: [28, 30],
    3: [48, 40],
    4: [-40, 40],
    5: [-20, 50],
    6: [0, 60],
    }

            
class GameWindow(pyglet.window.Window, Thread):
    tile_width = 480
    tile_height = 240
    scale = 0.25
    keyboard = key.KeyStateHandler()
    fx, fy = 0, 0

    def __init__(self, x, y, g, *args, **kwargs):
        self.window_width = kwargs.get('window_width', 800)
        self.window_height = kwargs.get('window_height', 600)

        Thread.__init__(self)
        super(GameWindow, self).__init__(*args, **kwargs)
        pyglet.clock.schedule_interval(self.update, 1.0/30.0)
        self.daemon = True
        self.tile_batch = pyglet.graphics.Batch()
        self.floor_batch = pyglet.graphics.Batch()
        self.egg_batch = pyglet.graphics.Batch()
        self.clients_batch = pyglet.graphics.Batch()

        self.s, self.clients, self.eggs, self.sprites, self.floor, self.bucket = [], [], [], [], [], []
        self.x, self.y, self.g = x, y, g

        self.push_handlers(self.keyboard)
        self.tile_img = pyglet.image.load('cube.png')
        self.tile_img2 = pyglet.image.load('cube2.png')
        self.player = pyglet.image.load('char.png')
        self.map = [[0] * x for _ in range(0, y)]
        self.fps_display = pyglet.clock.ClockDisplay()
        self.print_map()
        self.start()
                        
    def run(self):
        while True:
            message = self.g.s.read().split()
            data = self.bucket.append(message)

    def move_eggs(self):
        for i in range(0, len(self.eggs)):
            cx, cy = self.to_iso(self.eggs[i].map_x, self.eggs[i].map_y)
            cx += (self.tile_width / 2) * self.scale  - 30
            cy += self.tile_height * self.scale + 30
            self.eggs[i].set_position(cx, cy)

    def move_players(self):
        for i in range(0, len(self.clients)):
            cx, cy = self.to_iso(self.clients[i].map_x, self.clients[i].map_y)
            cx += (self.tile_width / 2) * self.scale  - 15
            cy += self.tile_height * self.scale + 30
            self.clients[i].set_position(cx, cy)

    def update_egg(self, num):
        for i in range(0, len(self.eggs)):
            if self.eggs[i].number == num:
                self.eggs.remove(self.eggs[i])
                return

    def update_player(self, x, y, pnumber, dead=0):
        for i in range(0, len(self.clients)):
            if self.clients[i].pnumber == pnumber:
                if dead != 0:
                    self.clients.remove(self.clients[i])
                    return
                else:
                    cx, cy = self.to_iso(x, y)
                    cx += (self.tile_width / 2) * self.scale - 15
                    cy += self.tile_height * self.scale + 30
                    self.clients[i].set_position(cx, cy)

    def print_player(self, x, y, pnumber):
        cx, cy = self.to_iso(x, y)
        cx += (self.tile_width / 2) * self.scale  + 30
        cy += self.tile_height * self.scale + 30
        client = pyglet.sprite.Sprite(self.player, x=cx, y=cy, batch=self.clients_batch)
        client.pnumber = pnumber
        client.map_x, client.map_y = x, y
        self.clients.append(client)


    def print_map(self):
        if self.s is not None:
            del self.s[:]
        for y in reversed(range(0, self.y)):
            for x in reversed(range(0, self.x)):
                cx, cy = self.to_iso(x, y)
                sprite = pyglet.sprite.Sprite(self.tile_img2, x=cx, y=cy, batch=self.tile_batch)
                sprite.scale = self.scale
                self.s.append(sprite)

    def print_all_objects(self):
        for i in range(0, len(self.floor)):
            cx, cy = self.to_iso(self.floor[i].map_x, self.floor[i].map_y)
            cx += (self.tile_width / 2) * self.scale  + coord[self.floor[i].type][0]
            cy += self.tile_height * self.scale + coord[self.floor[i].type][1]
            self.floor[i].set_position(cx, cy)

    def print_objects(self, x, y, liste):
        if liste == 0:
            return
        self.map[y][x] = liste
        for i in range(0, len(liste)):
            var = False
            for elem in self.floor:
                if elem.map_x == x and elem.map_y == y and elem.type == i:
                    if liste[i] == 1:
                        var = True
                    elif liste[i] == 0:
                        self.floor.remove(elem)
                        var = True
                elif liste[i] == 0:
                    var = True
            if var == False:
                cx, cy = self.to_iso(x, y)
                cx += (self.tile_width / 2) * self.scale + coord[i][0]
                cy += self.tile_height * self.scale + coord[i][1]
                sprite = pyglet.sprite.Sprite(objects[i], x=cx, y=cy, batch=self.floor_batch)
                sprite.set_position(cx, cy)
                sprite.map_x, sprite.map_y = x, y
                sprite.type = i
                sprite.scale = self.scale
                self.floor.append(sprite)

    def add_egg(self, num, x, y):        
        cx, cy = self.to_iso(x, y)
        cx += (self.tile_width / 2) * self.scale -30
        cy += self.tile_height * self.scale + 30
        _egg = pyglet.sprite.Sprite(egg, x=cx, y=cy, batch=self.egg_batch)
        _egg.number = num
        _egg.scale = self.scale
        _egg.map_x, _egg.map_y = x, y
        self.eggs.append(_egg)

    def to_iso(self, x, y):
        screen_x = floor((x - y) * (self.scale * self.tile_width / 2)) + self.fx
        screen_y = floor((x + y) * (self.scale * self.tile_height / 2)) + self.fy
        return [screen_x, screen_y]


    def update(self, dt):
        redraw = False
        try:
            data = self.bucket.pop()
        except IndexError:
            pass
        else:
            if data[0] == 'bct':
                data.pop(0)
                x, y = int(data.pop(0)), int(data.pop(0))
                list = []
                for i in data:
                    i = int(i)
                    if i > 0:
                        i = 1
                    list.append(i)
                self.print_objects(x, y, list)
                redraw = True
            elif data[0] == 'pnw':
                data.pop(0)
                self.print_player(int(data[1]), int(data[2]), int(data[0][1:]))
                redraw = True
            elif data[0] == 'ppo':
                data.pop(0)
                self.update_player(int(data[1]), int(data[2]), int(data[0][1:]))
            elif data[0] == 'pdi':
                data.pop(0)
                self.update_player(0, 0, int(data[0][1:]), dead=1)
            elif data[0] == 'enw':
                data.pop(0)
                self.add_egg(int(data[0][1:]), int(data[2]), int(data[3]))
            elif data[0] == 'eht' or data[0] == 'edi':
                data.pop(0)
                self.update_egg(int(data[0][1:]))

        if self.keyboard[key.Q]:
            pyglet.app.exit()

        fx = self.fx + (self.keyboard[key.RIGHT] - self.keyboard[key.LEFT]) * 350 * dt
        fy = self.fy + (self.keyboard[key.DOWN] - self.keyboard[key.UP]) * 350 * dt
        if fy != self.fy or fx != self.fx:
            self.fx = fx
            self.fy = fy
            redraw = True
        if redraw == True:
            self.print_map()
            self.print_all_objects()
            self.move_eggs()
            self.move_players()

    def on_draw(self):
        self.clear()
        self.tile_batch.draw()
        self.floor_batch.draw()
        self.egg_batch.draw()
        self.clients_batch.draw()

if __name__ == "__main__":
    game = GameWindow(width=window_width, height=window_height)
    pyglet.app.run()
