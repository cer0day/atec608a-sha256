# atec608a-sha256
En este trabajo de realiza una prueba de rendimiento, ejecutando el algoritmo SHA256 en una placa Arduino UNO vs criptoprocesador ATECC608A

#Nota: Aunque para esta prueba se utilizo el criptop´rocesador ATECC608A, la libreria utilizada es la del ATECC508A, por ser la unica disponible hasta el momento para arduino

#Link de la libreria para ATECC508A
https://github.com/GabrielNotman/cryptoauthlib


#Modificaciones a la libreria para esta prueba

Archivo modificado          |  Funion modificada    |      No. de linea    |     Valor por defecto    |      Valor para esta prueba

eccX08 comm marshaling.h       SHA DELAY                     579                     0.7 y 0.5                   0 y 0

eccX08 comm.h                  ECCX08 COMMAND_EXEC MAX        31                    120 y 0.5                    0 y 0
