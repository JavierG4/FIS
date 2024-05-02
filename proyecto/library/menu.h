#include <iostream>

#include "usuario.h"
#include "horario.h"
#include "aulas.h"
#include "libros.h"
#include "info_biblio.h"
#include "ver_eventos.h"
#include "eventos.h"
#include "discusion.h"
#include "foro.h"
#include "seguridad.h"
#include "faq.h"

#define GREEN "\033[32m"
#define RESET "\033[0m"

void MenuForo(Usuario&);
void MostrarMenu(Horario);
void MenuRegistrado(Usuario&, Horario, Eventos);