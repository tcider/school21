eval $(minikube docker-env)
kubectl delete -f ../yaml/telegraf.yaml
docker build -t telegraf-image ../telegraf/
kubectl apply -f ../yaml/telegraf.yaml
