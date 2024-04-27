#ifndef AULAS_H
#define AULAS_H

#include "horario.h"
#include "usuario.h"

void imprimir_recordatorio(Usuario& usuario);
void reservar_aula(Horario& horario, Usuario& usuario);
void anular_reserva_aula(Horario& horario, Usuario& usuario);
void ver_reservas_aulas(Usuario& usuario);

#endif //AULAS_H