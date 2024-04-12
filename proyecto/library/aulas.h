#ifndef AULAS_H
#define AULAS_H

#include "horario.h"
#include "usuario.h"

void reservar_aula(Horario& horario, Usuario& usuario);
void anular_reserva_aula(Horario& horario, Usuario& usuario);

#endif //AULAS_H