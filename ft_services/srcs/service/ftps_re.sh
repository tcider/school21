eval $(minikube docker-env)
kubectl delete -f ../yaml/ftps.yaml
docker build -t ftps-image ../ftps/
kubectl apply -f ../yaml/ftps.yaml
