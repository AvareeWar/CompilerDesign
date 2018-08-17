; Variable: r0	Offset: 1
; Variable: r1	Offset: 2
  load %3,2.5
  copy %1, %3
  load %4,2.5
  copy %2, %4
  mul%1, %2
  stdOutPrintLn %1
  load %0,0
  stopWSuccess
