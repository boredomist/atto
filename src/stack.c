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

#include "stack.h"

#include <stdio.h>

Stack *StackNew() {
  Stack* s = malloc(sizeof(Stack));
  s->top = 0;
  return s;
}

void StackDestroy(Stack* s) {
  UNUSED(s);
  // nothing to do as long as s->values is statically allocated
}

void push(Stack* s, TValue v) {
  if(s->top >= MAX_STACK_SIZE) {
    puts("Stack full.");
    return;
  }
  s->values[s->top++] = v;
}

TValue pop(Stack* s) {
  return s->values[--s->top];
}

int filled(Stack* s) {
  return s->top >= MAX_STACK_SIZE;
}

void print_stack(Stack* s) {
  if(s->top == 0) {
    puts("Stack is empty.");
    return;
  }

  printf("Stack at %p:\n", (void*)s);
  int i;
  for(i = 0; i < s->top; ++i) {
    // TODO: string print
    printf("[%d]\t=>\t%Lf\n", i, NVALUE(s->values[i]));
  }
}
