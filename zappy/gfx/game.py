from connexions import Sock

class Game(object):
    teams = {}
    map = {}

    def __init__(self, Sock):
        self.s = Sock

    def welcome(self):
        self.s.send("GRAPHIC")

    def loop_until_msz(self):
        while True:
            message = self.s.read().split()
            if message[0] == 'BIENVENUE':
                self.welcome()
                continue
            mes = message.pop(0)
            if mes == 'msz':
                self.msz(message)
                break

    def smg(self, window, message):
        if not message[0]:
            return None
        msg = "".join(message)
        print "server says " + msg

    def msz(self, message):
        self.x, self.y = int(message[0]), int(message[1])
        self.s.send("msz")
