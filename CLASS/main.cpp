#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <conio.h>

#include "global.h"

#include "parse.h"
#include "identify.h"
#include "handler.h"

#include "ksql.h"

int main() {

        cls();
        KSQL sql;
        sql.init();
        return 0;
}
