# -*- coding: iso-8859-1 -*-
import time
import serial
 
# Iniciando conexión serial
arduinoPort4 = serial.Serial('COM4', 115200, timeout=3)
arduinoPort6 = serial.Serial('COM6', 115200, timeout=3)
flagCharacter = 'k'
 
# Retardo para establecer la conexión serial
time.sleep(1.8) 

arduinoPort4.write(flagCharacter)
arduinoPort6.write(flagCharacter)

getSerialValue4 = arduinoPort4.readline()
getSerialValue6 = arduinoPort6.readline()
#getSerialValue = arduinoPort.read()
#getSerialValue = arduinoPort.read(6)
print '\nSHA256 ejecutado en placa arduino UNO: %s' % (getSerialValue4)
print '\nSHA256 ejecutado en criptoprocesador ATECC608A: %s' % (getSerialValue6)
 
# Cerrando puerto serial
arduinoPort4.close()
arduinoPort6.close()