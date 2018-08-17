; Variable: i	Offset: 1
; Variable: j	Offset: 2
; Variable: result	Offset: 3
  load %4,1
  copy %1, %4
  load %5,2
  copy %2, %5
equal%6, %1, %2
  ifFalseGoto %6, label0%%
  load %7,true
  copy %3, %7
  goto label0%%
label0%:
  load %0,0
  stopWSuccess
