eval $(minikube docker-env)
kubectl delete -f ../yaml/influxdb.yaml
docker build -t influxdb-image ../influxdb/
kubectl apply -f ../yaml/influxdb.yaml
