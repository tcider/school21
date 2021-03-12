eval $(minikube docker-env)
kubectl delete -f ../yaml/wordpress.yaml
docker build -t wordpress-image ../wordpress/
kubectl apply -f ../yaml/wordpress.yaml
