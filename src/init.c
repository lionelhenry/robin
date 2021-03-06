#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <stdbool.h>


extern SEXP robin_lang_prom(SEXP);
extern SEXP prim_invoke(SEXP, SEXP, SEXP, SEXP);
extern SEXP prim_ptr_invoke(SEXP, SEXP, SEXP, SEXP);
extern SEXP r_env_mirror(SEXP, SEXP);
extern SEXP robin_intl(SEXP);
extern SEXP robin_is_missing(SEXP);
extern SEXP robin_prim_offset(SEXP);
extern SEXP robin_prim_ptr(SEXP);
extern SEXP robin_prom_env(SEXP);
extern SEXP robin_prom_expr(SEXP);
extern SEXP robin_promise(SEXP);
extern SEXP sym_table();
extern SEXP sym_unbound();

static const R_CallMethodDef call_entries[] = {
  {"r_env_mirror",          (DL_FUNC) &r_env_mirror, 2},
  {"robin_lang_prom",       (DL_FUNC) &robin_lang_prom, 1},
  {"robin_intl",            (DL_FUNC) &robin_intl, 1},
  {"robin_is_missing",      (DL_FUNC) &robin_is_missing, 1},
  {"robin_prim_invoke",     (DL_FUNC) &prim_invoke, 4},
  {"robin_prim_ptr_invoke", (DL_FUNC) &prim_ptr_invoke, 4},
  {"robin_prim_offset",     (DL_FUNC) &robin_prim_offset, 1},
  {"robin_prim_ptr",        (DL_FUNC) &robin_prim_ptr, 1},
  {"robin_prom_env",        (DL_FUNC) &robin_prom_env, 1},
  {"robin_prom_expr",       (DL_FUNC) &robin_prom_expr, 1},
  {"robin_promise",         (DL_FUNC) &robin_promise, 1},
  {"robin_sym_table",       (DL_FUNC) &sym_table, 0},
  {"robin_sym_unbound",     (DL_FUNC) &sym_unbound, 0},
  {NULL, NULL, 0}
};


void R_init_robin(DllInfo* dll) {
  R_registerRoutines(dll, NULL, call_entries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
