; Variable: i	Offset: 1
; Variable: b	Offset: 2
  load %3,2
  copy %1, %3
equal%4, %1, %1
  copy %2, %4
  stdOutPrintLn %2
  load %0,0
  stopWSuccess
