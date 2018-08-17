PROGRAM eight;

VAR i,sum : Integer;

BEGIN
  sum := 0;
  FOR  i := 1 TO 10 DO
    sum := sum + i;

  WRITELN(sum)
END.
