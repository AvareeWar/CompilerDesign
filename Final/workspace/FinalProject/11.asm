; Variable: i	Offset: 1
  load %2,1
  copy %2, %1
label0%: 
  load %3,10
  greater %4 , %1 , %3
  ifTrueGoto %4 , label1%
  stdOutPrint %1
  add %1 , 1
  goto label0%
label1%:
  load %0,0
  stopWSuccess
