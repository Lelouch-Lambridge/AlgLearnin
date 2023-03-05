def search(a_list,someshit):
 if someshit not in a_list: return None
 s_list = sorted(a_list)
 debut = 0
 fin = len(a_list)-1
 found = False
 while debut<=fin and not found:
  milieu = (debut+fin)//2
  print(f"{debut}:{milieu}:{fin},{s_list},{s_list[milieu]}:{someshit}")
  if s_list[milieu] == someshit:
   found = not found
  elif s_list[milieu] < someshit:
   if milieu != debut: debut = milieu
   else: debut = fin
  elif someshit < s_list[milieu]:
   if milieu != fin: fin = milieu
   else: fin = debut
  else: break
 return (sorted(range(len(a_list)), key=(lambda k: a_list[k]))[milieu]) if found else None

if __name__ == "__main__":
 lit = list("acdbghtsip")+list(map(str,[1,6,3,4,5]))
 f = search(lit,"4")
 print(f)
 if f != None:
  print(lit[f])
