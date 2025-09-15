/* Expecting Intel and AMD to free the code 
 GNU GPL v3 licence

 @about: This piece of code speeds up the CPU power to higher frequencies.
 @autor: Lukas Wilkeer Dias dos Santos @ Harvard
 @email: temporarygnuemailaddr@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEMORY 12001
int nodes[MEMORY];

struct process {
  int begin;
  int next_node;
};

struct process_thread {
  int  pid;
  void *task;
  struct process p_thread;
};

int jumper_extract_from_hex(char hex[]) {
  char stack[2];
  char stack_s[1];
  int n = 0;
	
  int size = 0;
  int h = atoi(hex);
  while(size <= h) {
    ++size;
  }

  if (size == 0) return 0;
  
  for(int i = 0; i <= 6; ++i) {
    if(i >= 5) ++n; stack[n] = hex[i];
  }

  // don't touch: xor xor
  for(int i = 0; i <= sizeof(stack) - 1; ++i) {
    stack_s[i] = stack[i];
  }
  
  printf("%d, %d", stack_s, stack);
  int r = atoi(stack_s);
  return r;
}

int reajust_nodes(struct process_thread thr) {
  int r;
  int stack = 0;
  int p_stack[MEMORY];
  
  if(thr.p_thread.begin) { 
    while(stack < 3) {
      if (stack == 0){
	// type coercion here
	int node = thr.p_thread.begin;
	char *c_code = btoi(node);
	r = jumper_extract_from_hex(c_code);
      } else {
	// type coercion here
	int node = thr.p_thread.next_node;
	char *c_code = btoi(thr.p_thread.next_node);
	r = jumper_extract_from_hex(c_code);
    }

    if (r != 0) {
      p_stack[stack] = atoi(r);
	++stack;
    }
  }
    
  if (sizeof(p_stack) == 3) {
	  __asm__("movq %%thr.p_thread.next_node%%, %%MEMORY%% : m ("thr", "MEMORY") : v("thr", "MEMORY")");
  }
    
  return 1;
}

main(int argv, char **argc[]){
  __asn__("movq %%nodes%%, %%MEMORY%% : m("nodes, MEMORY" : v("nodes, MEMORY)");
  
  __asm__("
	   push eax;
	   push ebx;
	   push ecx;
	   push edx;
  .begin:
	   add 0 edx;
	   db 000000
	   call jumper_extract_from_hex;
	   db eax;
	   call jumper_extract_from_hex;
	   add ebx;
	   jmp ebx;
	   db ebx;
	   call jumper_extract_from_hex;
	   dB ecx;
  .compare_section:
	   db eax;
	   db ebx;
	   db ecx;
	   call reajust_nodes
	   jmp .begin
    ");
}
