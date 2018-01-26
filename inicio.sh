sudo iw reg set US
sudo ip link set wlan0 down
sudo iw dev wlan0 set type ocb
sudo ip link set wlan0 up
sudo iw --debug  dev wlan0 ocb join 5890 10MHZ
