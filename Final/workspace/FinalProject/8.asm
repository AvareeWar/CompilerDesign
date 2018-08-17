; Variable: i	Offset: 1
; Variable: sum	Offset: 2
  load %3,0
  copy %2, %3
  load %4,1
  copy %4, %1
label0%: 
  load %5,10
  greater %6 , %1 , %5
  ifTrueGoto %6 , label1%
  add%2, %1
  copy %2, %2
  add %1 , 1
  goto label0%
label1%:
  stdOutPrintLn %2
  load %0,0
  stopWSuccess
