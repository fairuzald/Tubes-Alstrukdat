#include "../../adt/input/charmachine.h"
#include "../../adt/input/wordmachine.h"

/*include fungsi lain*/
#include "../profile/profile.h"
#include "../user/user.h"

void readInput(Word *command);
/*membaca kata pertama dari input dan mereturn nama command yang akan
 * dijalankan*/
void readInputNoIgnore(Word *command);