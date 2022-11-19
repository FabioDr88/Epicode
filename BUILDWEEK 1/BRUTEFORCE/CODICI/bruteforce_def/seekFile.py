import os
from os.path import isfile
from colorama import Fore
from colorama import Style

def seekFile(sought_file):

  scelta = "n"

  while scelta == "n":

    path = input(f"Inserisci la PATH in cui cercare il file -- {sought_file} -- >>> ")

    try:
      files = [f for f in os.listdir(path) if os.path.isfile(f)]
      found_files = []
      print(f"\nFile nella directory ---> {path}:")
      for f in files:
        if sought_file in f:
          print(f"  [+] {Fore.GREEN}{f}{Style.RESET_ALL}")
          found_files.append(f)
        else:
          print(f"  [+] {f}")
    except:
      print("PATH sbagliato o inesistente, RIPROVA!\n")
      continue

    if(found_files == []):
      print("\nFile non trovato!")
      scelta = input("\nVuoi cercare in una nuova directory? (s/n) >>> ")
    else:
      print("\nCorrispondenze trovate nella directory:")
      for idx,f in enumerate(found_files):
        print(f"  [{Fore.GREEN}{idx + 1}{Style.RESET_ALL}] {f}")
      scelta_file = int(input("\nQuale è il file che cerchi? >>> ")) - 1


      scelta = input("\nVuoi proseguire a la ricerca? (s/n) >>> ")


    return found_files[scelta_file]
