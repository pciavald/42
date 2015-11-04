#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Commandes:
install : installe pyglet, et crée le fichier gfx
clean: supprime les fichiers pyc
re: refais le fichier gfx
fclean: supprime les pyc et gfx
uninstall: supprime pyglet
"
fi

case "$1" in
'install')
	pip install --user hg+https://code.google.com/p/pyglet/
	echo '#!'`which python` > gfx
	cat main.py >> gfx
	chmod 755 gfx
;;
'clean')
	rm -rf connexions.pyc game.pyc tile.pyc
;;
'fclean')
	rm -rf connexions.pyc game.pyc tile.pyc gfx
;;
're')
	echo '#!'`which python` > gfx
	cat main.py >> gfx
	chmod 755 gfx
;;
'uninstall')
    pip uninstall pyglet
esac