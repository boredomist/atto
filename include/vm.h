/*   This file is part of Atto.
 *
 *   Atto is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Atto is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Atto.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _VM_H_
#define _VM_H_

#include "block.h"

typedef struct {
  unsigned just_putting_this_here_so_compiler_doesnt_complain_about_an_empty_struct_kthnx;
  // constants, functions, etc. go here
} AttoVM;

AttoVM *AttoVMNew();
void    AttoVMDestroy(AttoVM*);
TValue  vm_interpret(AttoVM*, AttoBlock*, int, int, Stack*);
#endif /* _VM_H_ */