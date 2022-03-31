def caught_speeding(speed, is_birthday):
  if(speed<=60+(is_birthday*5)):
    return 0
  elif(61+(is_birthday*5)<=speed<=80+(is_birthday*5)):
    return 1
  elif(81+(is_birthday*5)<=speed):
    return 2