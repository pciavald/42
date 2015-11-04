import socket

class Sock(object):
    s = None
    port = None
    host = None
    def __init__(self, HOST, PORT):
        try:
            if HOST == 'localhost':
                HOST = '127.0.0.1'
            self.host = socket.gethostbyname(HOST)
            self.port = int(PORT)
            print ">> Trying to connect to %s:%s..." % (self.host, self.port)
            self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.s.connect((self.host, self.port))
            print "<< Connected to %s:%s !" % (self.host, self.port)
        except Exception as e:
            print str(e)
            exit()
    def close(self):
        print ">> Closing connection %s:%s..." % (self.host, self.port)
        self.s.close()
        exit()
    def read(self):
        message = ''
        while True:
            tmp_message = self.s.recv(1)
            if tmp_message == "\n":
                break
            message += tmp_message
        return message
    def send(self, message):
        self.s.send(message)
        self.s.send('\n')
