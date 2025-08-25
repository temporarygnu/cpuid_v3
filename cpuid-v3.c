/* Expecting Intel and AMD to free the code 
 GNU GPL v3 licence

 @about: This piece of code speeds up the CPU power to higher frequencies.
 @autor: Lukas Wilkeer Dias dos Santos @ Harvard
 @email: temporarygnuemailaddr@gmail.com
*/

#define MEMORY 12001
int nodes[MEMORY];

struct process {
  int begin;
  int next_node;
};

struct process_thread {
  int begin;
  int .pid;
  void *task;
  struct process p_thread;
};

int jumper_extratect_from_hex(char hex[]) {
  int stack[1];
  int n = 0;
	
  int size = 0;
  while(hex) {
    ++size;
  }

  if (size == 0) return 0;
  
  for(int i = 0; i <= 6; ++i) {
    if(i >= 5) ++n; stack[n] = hex[i];
  }

  int s = atoi(stack);
  return s;
}
  
int reajust_nodes(processs_thread thr) {
  int stack = 0;
  int p_stack[];
  
  if(thr->begin->next_node != NULL) { 
    while(stack < 3) {
      int r = if (stack == 0): jumper_extract_from_hex(thr->begin); else: jumper_extract_from_hex(thr->p_thread->next_node);
      if (r != NULL) {
	p_stack[stack] = r;
	++stack;
      }
    }
  }

  if (p_stack == 3) __asm__("movq %%thr->p_thread->next_node%% %%MEMORY%% : m (thr, MEMORY) : v(thr, MEMORY)");
  return 1;
}

main(int argv, char **argc[]){
  __asn__("movq %%Nnodes%% %%MEMORY%%");
  
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
