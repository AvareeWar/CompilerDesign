PROGRAM nine;

VAR i,sum : Integer;

BEGIN
  sum := 0;
  FOR  i := 10 DOWNTO 1 DO
    sum := sum + i;

  WRITELN(sum)
END.
