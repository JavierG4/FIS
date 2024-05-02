#
#AUTORES :Javier González Brito .

clean :
	rm -f *.o Programa doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;

push :
	git add .
	git commit -m mejora
	git push

pull:
	git pull
	
actu:
	git pull
	git add .
	git commit -m actualización
	git push
program:
	g++ -std=c++17 -g -I../library -o Biblioteca estanteria.cc libros.cc usuario.cc main.cc seguridad.cc horario.cc aulas.cc info_biblio.cc ver_eventos.cc eventos.cc menu.cc foro.cc discusion.cc faq.cc
