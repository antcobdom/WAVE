# WAVE
## Implementacion de 1609 (WAVE) sobre 802.11p
### Instrucciones para la compilación de kernel
https://gist.github.com/lisovy/80dde5a792e774a706a9
### Instrucciones para habilitar 802.11p
* Desactivar *network-manager*:
    - `sudo stop network-manager`  
* Ejecutar el script para **[habilitar 802.11p](inicio.sh)**
### Instrucciones para ejecutar [1609](1609/)
* `make all`
* Abrir otro terminal y ejecutar *tcpdump* para que escuche en la interfaz deseada (wlan0 en este caso):
    - `sudo tcpdump -ni wlan0 -s0 -w wsm-pcap -vvv`
    - Con esto estamos volcando los datos recopilados a un fichero llamado *wsm-pcap*.
* En el terminal anterior ejecutar:
    - `./wireless wlan0`
    - Si la interfaz es otra, cambiar wlan0 por la correcta
    - Esta ejecución manda 100 paquetes a difusión con contenido aleatorio (*random*)
* Si se desea, se puede abrir con Wireshark el fichero *wsm-pcap* para ver los paquetes enviados. 
