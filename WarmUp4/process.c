# include <stddef.h>
# include <unistd.h>
# include <proc/readproc.h>

# include "mempool.h"
# include "tree.h"


/* process_set_add(set, pid) tries to add the process pid to the list and returns it */
/* if it's already in the list, returns the process node                             */
/* if it's the first encounter of the process, it'll add it to the process list      */
/* the process will be set as the root of process tree if pid==1                     */


struct process* process_set_add(struct process_set *set, pid_t pid){
  if (process_set_find(set, pid)){
    //if pif exist, return
    return(process_set_find(set, pid));
  }
  else
    {
      //if doesn't exist create node + add to the list
      struct process* newproc = mempool_alloc(set->pool, sizeof(process));
      newproc.pid = pid;
      newproc = container_of(struct process, list, cur -> next);
      list_push_front(set->list, &(newproc->list));
      if(pid == 1)
	//if pid = 1 set root of process tree to this node
	set -> tree = newproc -> tree;
      return(set);
    }
}

/* process_set_attach_process(set, procinfo) attaches a new process to the set       */
/* this function is responsible to add the process and attach it to its parent       */
void process_set_attach_process(struct process_set *set, proc_t *procinfo){
  //traduire les phrases de marwan pour trouver les fonctions
}

/* make_process_set() creates and populates the set of processes                     */
struct process_set* make_process_set(void);
