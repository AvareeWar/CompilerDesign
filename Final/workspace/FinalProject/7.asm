; Variable: i	Offset: 1
; Variable: j	Offset: 2
; Variable: result	Offset: 3
  load %4,1
  copy %1, %4
  load %5,2
  copy %2, %5
equal%6, %1, %2
  ifFalseGoto %6, label1%%
  load %7,true
  copy %3, %7
  goto label0%%
label1%%
  load %8,false
  copy %3, %8
label0%:
  load %0,0
  stopWSuccess
