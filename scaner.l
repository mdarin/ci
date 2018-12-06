%{
extern char ImitatorName[];
extern char ComplexName[];
%}
%%
\{\$complex\} {
  fprintf(yyout, "%s", ComplexName);
}
\{\$imitator\} {
  fprintf(yyout, "%s", ImitatorName);
}
%%
extern int yywrap (void)
{
  int status = 1;
  if(!feof(yyin))
  {
    status = 0;
  }
  return status;
}
