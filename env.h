/************************************************

  env.h -

  $Author: matz $
  $Revision: 1.3 $
  $Date: 1994/08/12 11:06:39 $
  created at: Mon Jul 11 11:53:03 JST 1994

************************************************/
#ifndef ENV_H
#define ENV_H

extern struct ENVIRON {
    VALUE self;
    int argc;
    VALUE *argv;
    struct RClass *current_module;
    struct RClass *last_class;
#ifdef USE_CALLER
    char *file;
    int line;
#endif
    ID last_func;
    ID *local_tbl;
    VALUE *local_vars;
    int in_eval;
    struct BLOCK *block;
    int iterator;
    int flags;
    struct ENVIRON *prev;
} *the_env;

#define ITERATOR_P() (the_env->iterator == 1 || the_env->iterator == 2)

#undef Qself
#define Qself the_env->self
#define the_class the_env->current_module

#define DURING_ITERATE  1
#define DURING_RESQUE   2
#define DURING_CALL     4
#define VARS_MALLOCED   8

#endif /* ENV_H */
