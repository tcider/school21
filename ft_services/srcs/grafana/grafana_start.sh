envsubst '${GRAFANA_PORT} ${GRAFANA_USER} ${GRAFANA_PASW}' < defaults.ini.tmp > defaults.ini
mv defaults.ini /grafana/conf/defaults.ini

envsubst '${INFLUX_PORT} ${INFLUX_USER} ${INFLUX_PASW}' < datasource.yaml.tmp > datasource.yaml
mv datasource.yaml /grafana/conf/provisioning/datasources/datasource.yaml

cp dashboards/dashboards.yaml /grafana/conf/provisioning/dashboards/dashboards.yaml
cp home.json /grafana/public/dashboards/home.json
cp dashboards/*.json /grafana/conf/provisioning/dashboards/

/grafana/bin/grafana-server --homepath=/grafana
