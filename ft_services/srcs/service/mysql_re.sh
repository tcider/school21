eval $(minikube docker-env)
kubectl delete -f ../yaml/mysql.yaml
docker build -t mysql-image ../mysql/
kubectl apply -f ../yaml/mysql.yaml
