#ifndef __DOCUMENTO_H_
#define __DOCUMENTO_H_

#include "linea.h"

struct Documento {
    Linea *linea;
    Documento *prox;
};


#endif  // __DOCUMENTO_H_
