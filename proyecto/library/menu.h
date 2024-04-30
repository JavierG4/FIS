#include <iostream>
#include "../library/usuario.h"
#include "horario.h"
#include "aulas.h"
#include "libros.h"
#include "info_biblio.h"
#include "ver_eventos.h"
#include "eventos.h"
#include "discusion.h"
#include "foro.h"

void MenuForo(Usuario&);
bool MostrarMenu(bool);
void MenuRegistrado(Usuario&, Horario, Eventos);