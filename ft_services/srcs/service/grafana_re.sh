eval $(minikube docker-env)
kubectl delete -f ../yaml/grafana.yaml
docker build -t grafana-image ../grafana/
kubectl apply -f ../yaml/grafana.yaml
