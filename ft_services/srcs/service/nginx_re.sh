eval $(minikube docker-env)
kubectl delete -f ../yaml/nginx.yaml
docker build --tag nginx-image ../nginx/
kubectl apply -f ../yaml/nginx.yaml
