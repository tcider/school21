envsubst '${INFLUX_PORT} ${INFLUX_USER} ${INFLUX_PASW}' < telegraf.conf.tmp > telegraf.conf
mv telegraf.conf /etc/telegraf/telegraf.conf

/usr/bin/telegraf
