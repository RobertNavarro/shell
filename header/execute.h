#ifndef __EXECUTE_H__
#define __EXECUTE_H__

#include "Token.h"
#include "ExeToken.h"
using namespace std;

int execute(ExeToken* token);
int execute(ExeToken* leftToken,ExeToken* rightToken );

#endif	
