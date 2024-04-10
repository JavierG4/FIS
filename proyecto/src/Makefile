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
	g++ -g -I../library -o Biblioteca usuario.cc main.cc seguridad.cc horario.cc aulas.cc